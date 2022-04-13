#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

int insert_word(int board[15][15],int lines,int jogada);
void validword(char *word,char *lista_palavras[]);
char loaddic(char * filename,char *lista_palavras);

#endif // WORD_H_INCLUDED
