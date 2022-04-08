#include "headers.h"
#include "gamemode.h"
#include "board.h"

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
