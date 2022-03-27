#include "headers.h"

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
void insert_word(int board[15][15],int direction,char palavra[15],int lines,int x,int y);
int Error(int i);
void help();



 int main()
{
    int board[15][15]={0};

    initboard(board,10,11);
    printboard(board,10,11);


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
        //Erro se a linhas e colunas nao cumprirem as restriçoes
        if(lines < 7 || lines > 15 || lines == 8|| lines ==10 || lines ==12 ||lines == 14)
        {
            Error(1);
            exit(0);
        }


        printf("\n\t%d   ",i+1); //print do numero das linhas
        if (i<9 ){printf(" ");}//ajustar o campo


        for(int j = 0; j < columns ; j++)
        {
            if(board[i][j]==0){printf(".  ");}
            else if(board[i][j]==1){printf("#  ");}
            else if(board[i][j]==2){printf("2  ");}
            else if(board[i][j]==3){printf("3  ");}
            else if(board[i][j]==4){printf("$  ");}
            else{printf("%c",board[i][j]);}


        }
    }
    printf("\n\n\t     ");
    for(int j = 0 ;j < columns; j++)
    {
        printf("%c  ",'A'+j); // print dos identificadores das colunas
    }
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

void insert_word(int board[15][15],int direction,char palavra[15],int lines,int x,int y)
{

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

        printf("");

        break;

    case 3:

        break;

    case 4:

        break;

    default:
        printf("-1");

    }
}

/*  . casa vazia, onde pode ser posta qualquer letra
    # casa proibida, onde não se pode pôr nenhuma letra
    2 casa onde a letra lá colocada vale o dobro dos pontos
    3 casa onde a letra lá colocada vale o triplo dos pontos
    $ casa onde a palavra lá colocada vale o dobro dos pontos
*/

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
    printf("\n *-h ajuda para o utilizador ");
    printf("\n *-t lxc dimensões do tabuleiro (linha x coluna).");
    printf("\n *-d filename nome do ficheiro de dicionário a utilizar ");
    printf("\n *-l filename nome do ficheiro com letras a usar nas jogadas");
    printf("\n *-m 5-20 número de letras que um jogador pode ter na sua mão para jogar");
    printf("\n *-n nn número de jogadas máximo a realizar ");
    printf("\n *-i filename define ficheiro com o tabuleiro a usar em alternativa a jogar num tabuleiro vazio");
    printf("\n *-j 1-4 modo de jogo 1 a 4 ");
    printf("\n *-o filename define ficheiro onde escrever o tabuleiro final.");
    printf("\n *- r filename define ficheiro para registo de todas as jogadas possíveis.");
    printf("\n____________________________________________");

}
