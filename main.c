#include "headers.h"

#define MAX_LENGHT 16

/*=============================================================================
 |   Assignment:  Palavras cruzadas 2021/2022
 |
 |       Author:  Luís Valência, Vasco Pereira
 |     Language:  C ,gcc gnu compiler
 |   To Compile:

 |
 |        Class:  Programacao Leec
 |
 |     Due Date:  22/04/2022
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:
 |
 |        Input:
 |
 |       Output:
 |
 |    Algorithm:
 |
 |   Required Features Not Included:
 |
 |   Known Bugs:
 |
 *===========================================================================*/
void printboard(int board[15][15],int lines, int columns);
void initboard(int board[15][15],int lines, int columns);
void insert_word(int board[15][15],int lines);
void validword(char word[MAX_LENGHT],char *lista_palavras[]);
int Error(int i);
void help();



 int main(int argc,char *argv[])
{
    int board[15][15]={0};
    int linhas=15,colunas=15;
    int option=0;
    int gamemode=0;





    while (((option = getopt(argc,argv,"h:t:d:l:m:n:i:j:o:r"))!=-1)){
            switch(option){
                case 'h' :
                    help();
                    return 0;
                break;

                case 't' :
                    //erro se as duas variaves nao forem lidas corretamente
                    if((sscanf(optarg,"%dx%d,&linhas,&colunas"))!=2)
                    {
                        Error(3);
                    }
                    //Erro se a linhas e colunas nao cumprirem as restriçoes
                    if(linhas < 7 || linhas > 15 || linhas == 8|| linhas ==10 || linhas ==12 ||linhas == 14 || linhas != colunas)
                    {
                        Error(3);

                        return -1;
                    }
                    break;

                case 'd' :
                    break;

                case 'l' :
                    break;

                case 'm' :
                    break;

                case 'n' :
                    break;

                case 'i' :
                    break;

                case 'j' :
                    if(sscanf(optarg,"%d",&gamemode)!=1)
                    {
                        Error(4);
                        return -1;
                    }
                    if(gamemode< 0 || gamemode > 4)
                    {
                        Error(4);
                        return -1;
                    }
                    break;

                case 'o' :
                    break;

                case 'r' :
                    break;

                default:
                    printf("\nArgumento desconhecido\n");
                    help();
                    return -1;

                    break;
            }
    }
    linhas=9;
    colunas=9;




    initboard(board,linhas,colunas);
    printboard(board,linhas,linhas);
    insert_word(board,linhas);
    printboard(board,linhas,colunas);



    return 0;

}



/** \brief Função que imprime o campo
 *
 *  \param
 *
 *      INPUT:board [15][15](int)board matrix
 *      INPUT:lines (int) number of lines in the matrix
 *      INPUT:Columns (int) number of columns in the matrix
 *  \return printf do tabuleiro
 */


void printboard(int board[15][15],int lines, int columns)
{

    for(int i = 0 ;i < lines ;i++ )
    {
        printf("\n\t%d",i+1); //print do numero das linhas
        if (i<9 ){printf(" ");}//ajustar o campo

        for(int j = 0; j < columns ; j++)
        {
            if(board[i][j]==0){printf(".  ");}
            else if(board[i][j]==1){printf("#  ");}
            else if(board[i][j]==2){printf("2  ");}
            else if(board[i][j]==3){printf("3  ");}
            else if(board[i][j]==4){printf("$  ");}
            else{printf("%c  ",board[i][j]);}
        }
    }
    printf("\n\t  ");
    for(int j = 0 ;j < columns; j++)
    {
        printf("%c  ",'A'+j); // print dos identificadores das colunas
    }
    printf("\n");
}



/** \brief Função que inicializa o campo
 *
 *  \param
 *
 *      INPUT:board [15][15](int)board matrix
 *      INPUT:lines (int) number of lines in the matrix
 *      INPUT:Columns (int) number of columns in the matrix
 *  \return tabuleiro inicializado
 */

void initboard(int board[15][15],int lines, int columns)
{

    //colocar o '0' que representa o simbolo '.'  no tabuleiro
    for( int i = 0; i < lines ; i++)
    {
        for(int j = 0 ; j < columns; j++)
        {
                board[i][j]=0;
        }
    }

    //colocar o '4' que representa o simbolo $ no tabuleiro
    board[0][0]=4;
    board[lines-1][0]=4;
    board[0][columns-1]=4;
    board[lines-1][columns-1]=4;

    //colocar o '3' no tabuleiro
    board[lines/2][0]=3;
    board[0][columns/2]=3;
    board[lines/2][columns-1]=3;
    board[lines-1][columns/2]=3;



    //colocar o '2' no tabuleiro
    for(int i = 0; i < lines ;i++)
    {
        for(int j = 0; j < columns ;j++)
        {
            if((i=j) && (j != columns-1))
            {
                board[i][j]=2;
            }
        }
    }

    for (int i = 0; i < lines ;i++)
    {
        for(int j = columns ;j >0 ; j--)
        {
            if (i+j == lines -1 && j != columns-1)
            {
                board[i][j]=2;
            }
        }
    }

    //colocar o numero '1' que representa o simbolo '#' no tabuleiro
    for(int i = 0; i < lines ;i++)
    {
        for(int j = 0; j < columns ;j++)
        {
            if(i== lines/2-1 || i== lines/2+1 )
            {
                board[i][1]=1;
                board[i][columns-2]=1;
            }
            if(i == 1 || i == lines-2)
            {
                board[i][columns/2-1]=1;
                board[i][columns/2+1]=1;

            }
        }
    }

}




/** \brief Função que coloca a palavra dentro do tabuleiro na direção especificada
 *
 * \param
 *        INPUT:array 2d do Tabuleiro do jogo
 *        INPUT:direção da palavra (v,h)
 *        INPUT:Array da palavra
 *        INPUT:Linhas do tabuleiro (==colunas)
 *        INPUT:Coordenada x
 *        INPUT:Coordenada y
 *
 * \return devolve o tabuleiro com a palavra colocada no sitio pretentido e na direção pretendida
 */

void insert_word(int board[15][15],int lines)
{
    char word[MAX_LENGHT] = "teste" ;
    char direction = 'h';
    int x=0;
    int y=0;
    char coluna;
    int jogada =0;
    int erro=0;


    do{
            erro=0;
            printf("\njogada:");
            if((scanf("%c %d %c %s",&coluna,&y,&direction,&word))!=4 ) {
                printf("\nNao consegui ler a jogada ");
                erro=1;
            }

            if (direction = 'H'){direction=='h';}
            if (direction = 'V'){direction=='v';}

            x= coluna - 65;//transforma a letra da coluna num numero

			if( x > 31 && x < 48){x -=32;} // transforma as minusculas em maiusculas

            if( x < 0 || x > lines || y < 0 || y > lines){printf("Erro de coordenadas");// se as coordenadas nao tiverem no pressuposto intervalo dá erro
                erro = 1;}

            if(jogada == 0 && direction == 'v'){printf("A primeira jogada tem de ser feita na horizontal");
                erro=1;}

            if((direction=='h' && strlen(word)+x> lines) ||(direction=='v' && strlen(word)+y > lines)){printf("Erro a palavra nao cabe no tabuleiro");
                erro=1;
            }

            //x é o numero da coluna A
            //y é o numero da linha 1

    }while(erro==1); //se nao houver erros a jogada continua


    switch(direction)
    {
    case 'v':
            for(int i = 0; i< lines ;i++){

                for(int j = 0; j < lines ;j++)
                {
                    if(i == y && j == x)
                    {
                            for(int i=0 ; i < strlen (word) ; i++)
                            {
                            if(board[y+i][x]==1){ // restrição a palavra passa numa casa proibida
                                    printf("erro nao pode colocar a palavra em casas proibidas");
                                    exit(1);
                                    }

                            board[y+i][x]=word[i];

                            }
                    }
                }
            }

        break;

    case 'h':

            for(int i = 0; i< lines ;i++){

                for(int j = 0; j < lines ;j++)
                {
                    if(i == y && j == x)
                    {

                        for(int i=0 ; i < strlen (word) ; i++)
                            {
                                if(board[y][x+i]==1){ // restrição a palavra passa numa casa proibida
                                    printf("erro nao pode colocar a palavra em casas proibidas");
                                    Error(2);
                                    }

                                board[y][x+i]=word[i];
                            }
                    }
                }
            }
        break;

    }

}

/** \brief Funcao que recebe uma palavra e verifica s essa palavra existe no dicionario pretendido
 *
 * \param
 *      INPUT:Palavra a procurar(char)
 *      INPUT:Lista alocada dinamicamente com o dicionario(char)
 *      OUTPUT:'1' se a palavra esta no dicionario,'0' se nao está
 *
 */

void validword(char word[MAX_LENGHT],char *lista_palavras[]){




}

void gamemode1(board,linhas){



}






/**\brief funçao que recebe um numero e imprime o tipo de erro cometido e mostra a função0 ajuda
 *
 * \param
 *      Input: numero do erro (i)
 *
 * \return Tipo de erro e mostra a mensagem de ajuda
 *
 */

int Error(int i)
{
    switch(i)
    {
    case 1:
        printf("Erro de input no board veja as regras: ");
        help();

        break;


    case 2:

        printf("Erro de input de palavra veja as regras");
        help();

        break;

    case 3:
        printf("\n_______________________________________________");
        printf("\nErro no input do tabuleiro (-t)");
        printf("\n *-t lxc dimensoes do tabuleiro (linha x coluna).");
        printf("\nO tabuleiro deve ser bidimensional ");
        printf("\nTem dimensoes maximas 15x15");
        printf("\nTem dimensoes minimas 9x9");
        printf("\nO numero de linhas e colunas deve ser impar.");
        printf("\n_______________________________________________");



        break;

    case 4:
        printf("\n_______________________________________________");
        printf("\nErro no input do modo de jogo (-j)");
        printf("\nPor favor escolha um modo de jogo de 1 a 4 ");
        printf("\n_______________________________________________");

        break;

    default:
        printf("-1");

    }
}




/** \brief função de que imprime mensagem ajuda
 *
 * \param
 *      Output:Mensagem de ajuda
 *
 *
 */

void help()
{
    printf("\n____________________HELP____________________");
    printf("\n Trabalho realizado por Luis Valencia e Vasco Pereira");
    printf("\n *-h ajuda para o utilizador ");
    printf("\n *-t lxc dimensoes do tabuleiro (linha x coluna).");
    printf("\n *-d filename nome do ficheiro de dicionario a utilizar ");
    printf("\n *-l filename nome do ficheiro com letras a usar nas jogadas");
    printf("\n *-m 5-20 número de letras que um jogador pode ter na sua mão para jogar");
    printf("\n *-n nn número de jogadas máximo a realizar ");
    printf("\n *-i filename define ficheiro com o tabuleiro a usar em alternativa a jogar num tabuleiro vazio");
    printf("\n *-j 1-4 modo de jogo 1 a 4 ");
    printf("\n *-o filename define ficheiro onde escrever o tabuleiro final.");
    printf("\n *- r filename define ficheiro para registo de todas as jogadas possiveis.");
    printf("\n____________________________________________");

}
