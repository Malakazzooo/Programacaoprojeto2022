#include "headers.h"
#include "gamemode.h"
#include "board.h"

/** \brief funcao que corre o gamemode 1
 *
 * \param
 *      INPUT:tabuleiro do jogo(int)
 *      INPUT:linhas do tabuleiro(int)
 *
 *      OUTPUT:gamemode 1
 */

void gamemode1(int board[15][15],int lines){

    int jogada = 0;

        initboard(board,lines);
        printboard(board,lines);
        do{
            insert_word(board,lines,jogada);
            printboard(board,lines);
            jogada++;
        }while (jogada < 10);
}

void gamemode2(int board[15][15],int lines){}
