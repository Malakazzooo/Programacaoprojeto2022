#include "headers.h"

#include "gamemode.h"

#include "board.h"

#define MAX_LENGHT 16

/*=============================================================================
 |   Assignment:  Palavras cruzadas 2021/2022
 |
 |       Author:  Luis Valencia(100010), Vasco Pereira()
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
int insert_word(int board[15][15],int lines,int jogada);
void validword(char word[MAX_LENGHT],char *lista_palavras[]);
void Error(int i);
void help();



 int main(int argc,char *argv[])
{
    int board[15][15]={0};
    int linhas=15,colunas=15;
    int option=0;
    int gamemode=1; //predefinicao de modo de jogo
    char *infile = NULL;
    char *outfile = NULL;
    FILE *fp;
    FILE *fpout;





    while (((option = getopt(argc,argv,":h:t:l:m:n:i:j:o:r"))!=-1)){
            switch(option){
                case 'h' :
                    help();
                    return 0;
                break;

                case 't' :
                    //erro se as duas variaves nao forem lidas corretamente
                    if((sscanf(optarg,"%dx%d",&linhas,&colunas))!=2)
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

                    infile = optarg;

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

                    outfile = optarg;
                    break;

                case 'r' :
                    break;
                case '?' :
                    if (optopt == 'i' || optopt=='t' || optopt=='d' || optopt=='l' || optopt=='m') {
                printf("Faltam argumentos \n");
                    }
                    break;

                default:
                    printf("\nArgumento desconhecido\n");
                    help();
                    return -1;

                    break;
            }
    }





    //*********************ficheiros************************

    //abrir o ficheiro de entrada
    if(infile)
    {
        printf("\n*A abrir o ficheiro %s *\n", infile);
        if ((fp= fopen(infile, "r"))==NULL)
        {
            printf("Não consegui abrir o ficheiro de entrada.\n");
            exit(-1);
        }
    }
    //abir o ficheiro de saida
    if(outfile)
    {
        printf("\n*A abrir o ficheiro %s *\n", outfile);
        if ((fpout= fopen(outfile, "r"))==NULL)
        {
            printf("Não consegui abrir o ficheirod de saida.\n");
            exit(-1);
        }
    }



    //*********************ficheiros************************


    if(gamemode==1){gamemode1(board,linhas);}





    return 0;

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
 * \return devolve o tabuleiro com a palavra colocada no sitio pretendido e na direção pretendida
 */

int insert_word(int board[15][15],int lines,int jogada)
{

    char word[MAX_LENGHT];
    char end[] ={"fim"};
    char direction;
    int x=0;
    int y=0;
    char coluna;
    int erro=0;


    do{
            erro=0;
            printf("\njogada:");
            if((scanf("%c%d%c %s",&coluna,&y,&direction,&word))!=4  ) {
                printf("\n");
                erro=1;
            }


            if (strcmp(word,end)==0){printf("\n*Fim do jogo*"); //se jogarmos fim o jogo acaba
                exit(1);}


            if (direction == 'H'){direction=='h';}
            if (direction == 'V'){direction=='v';}

            x= coluna - 65;//transforma a letra da coluna num numero
            y--;//acertar as linhas

			if( x > 31 && x < 48){x -=32;} // transforma as minusculas em maiusculas

            if( (x < 0 || x > lines) || (y < 0 || y > lines)){printf("Erro de coordenadas");// se as coordenadas nao tiverem no pressuposto intervalo dá erro
                erro = 1;}

            if(jogada == 0 && direction == 'v'){printf("A primeira jogada tem de ser feita na horizontal");
                erro=1;}

            if(jogada == 0 && y != lines/2 && x != lines/2 && (board[lines/2][lines/2]== 0|| board[lines/2][lines/2]== 1 || board[lines/2][lines/2]== 2 || board[lines/2][lines/2]== 3 || board[lines/2][lines/2]== 4)){printf("\nA primeira jogada tem de ser feita no meio do campo se nao houver la uma letra");
                erro=1;}//se nao houver uma palavra no meio do tabuleiro e obrigatorio jogar la primeiro


            if((direction=='h' && strlen(word)+x> lines) ||(direction=='v' && strlen(word)+y-1 > lines)){printf("Erro a palavra nao cabe no tabuleiro");
                erro=1;
            }





            //x é o numero da coluna A
            //y é o numero da linha 1

    }while(erro==1); //se nao houver erros a jogada continua


    if(direction == 'v'){

            for(int i = 0; i< lines ;i++)
            {
                for(int j = 0; j < lines ;j++)
                {
                    if(i == y && j == x)
                    {
                            for(int i=0 ; i < strlen (word) ; i++)
                            {
                                if(board[y+i][x]!=1 &&(board[y+i][x]==0 || board[y+i][x]==2 || board[y+i][x]==3 || board[y+i][x]==4 || board[y][x]==word[0])){
                                    board[y+i][x]=word[i];  //escreve a palavra
                                }else{printf("Nao pode escrever por cima de palavras");
                                        return -1;}

                                if(board[y+i][x]==1){// restrição a palavra passa numa casa proibida
                                    printf("erro nao pode colocar a palavra em casas proibidas");
                                    Error(2);
                                }

                            }
                    }
                }
            }
    }else if(direction == 'h'){
            for(int i = 0; i< lines ;i++)
            {
                for(int j = 0; j < lines ;j++)
                {
                    if(i == y && j == x)
                    {

                        for(int i=0 ; i < strlen (word) ; i++)
                            {
                                if(board[y][x+i]!=1 && (board[y][x+i]==0 || board[y][x+i]==2 || board[y][x+i]==3 || board[y][x+i]==4 || board[y][x]==word[0])){
                                    board[y][x+i]=word[i]; //escreve a palavra
                                }else{printf("Nao pode escrever por cima de palavras");
                                        return -1;}

                                if(board[y][x+i]==1){  // restrição a palavra passa numa casa proibida
                                    printf("erro nao pode colocar a palavra em casas proibidas");
                                    Error(2);
                                }
                            }

                    }
                }
            }
    }
    return 1;
}

/** \brief Funcao que recebe uma palavra e verifica s essa palavra existe no dicionario pretendido
 *
 * \param
 *      INPUT:Palavra a procurar(char)
 *      INPUT:Lista alocada dinamicamente com o dicionario(char)
 *      OUTPUT:'1' se a palavra esta no dicionario,'0' se nao está
 *
 */

void validword(char *word,char *lista_palavras[]){


}

/**\brief funçao que recebe um numero e imprime o tipo de erro cometido e mostra a função0 ajuda
 *
 * \param
 *      INPUT: numero do erro (i)
 *
 *      OUTPUT: Tipo de erro e mostra a mensagem de ajuda
 *
 */

void Error(int i)
{
    switch(i)
    {
    case 1:
        printf("Erro de input no board veja as regras: ");
        help();

        break;


    case 2:

        printf("\nErro de input de palavra veja as regras");
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
 *      OUTPUTt:Mensagem de ajuda
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
