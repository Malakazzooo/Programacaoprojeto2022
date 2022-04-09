#include "headers.h"
#include "board.h"


/** \brief Função que imprime o campo
 *
 *  \param
 *
 *      INPUT:board [15][15](int)board matrix
 *      INPUT:lines (int) number of lines in the matrix
 *      INPUT:Columns (int) number of columns in the matrix
 *
 *      OUTPUT:printf do tabuleiro
 */


void printboard(int board[15][15],int lines)
{

    for(int i = 0 ;i < lines ;i++ )
    {
        printf("\n\t%d",i+1); //print do numero das linhas
        if (i<9 ){printf(" ");}//ajustar o campo

        for(int j = 0; j < lines ; j++)
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
    for(int j = 0 ;j < lines; j++)
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
 *
 *      OUTPUT:tabuleiro inicializado
 **/

void initboard(int board[15][15],int lines)
{

    //colocar o '0' que representa o simbolo '.'  no tabuleiro
    for( int i = 0; i < lines ; i++)
    {
        for(int j = 0 ; j < lines; j++)
        {
                board[i][j]=0;
        }
    }

    //colocar o '4' que representa o simbolo $ no tabuleiro
    board[0][0]=4;
    board[lines-1][0]=4;
    board[0][lines-1]=4;
    board[lines-1][lines-1]=4;

    //colocar o '3' no tabuleiro
    board[lines/2][0]=3;
    board[0][lines/2]=3;
    board[lines/2][lines-1]=3;
    board[lines-1][lines/2]=3;



    //colocar o '2' no tabuleiro
    for(int i = 0; i < lines ;i++)
    {
        for(int j = 0; j < lines ;j++)
        {
            if((i=j) && (j != lines-1))
            {
                board[i][j]=2;
            }
        }
    }

    for (int i = 0; i < lines ;i++)
    {
        for(int j = lines ;j >0 ; j--)
        {
            if (i+j == lines -1 && j != lines-1)
            {
                board[i][j]=2;
            }
        }
    }

    //colocar o numero '1' que representa o simbolo '#' no tabuleiro
    for(int i = 0; i < lines ;i++)
    {
        for(int j = 0; j < lines ;j++)
        {
            if(i== lines/2-1 || i== lines/2+1 )
            {
                board[i][1]=1;
                board[i][lines-2]=1;
            }
            if(i == 1 || i == lines-2)
            {
                board[i][lines/2-1]=1;
                board[i][lines/2+1]=1;

            }
        }
    }

}
