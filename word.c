#include "headers.h"
#include "gamemode.h"
#include "board.h"
#include "help.h"
#define MAX_LENGHT 16
#define REALLOC_SIZE 10

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
            if((scanf("%c%d%c%s",&coluna,&y,&direction,&word))!=4  ) {
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

void liberta_lista_palavras(char *lista_palavras[], int n_palavras)
{
    int i;

    if (lista_palavras!=NULL) {
        for (i=0 ; i < n_palavras ; i++)
            if (lista_palavras[i]!=NULL)
                free(lista_palavras[i]);
        free(lista_palavras);
    }
}

char loaddic(char *filename,char **lista_palavras){

    int n_palavras=0;
    int resultado;
    char formato[MAX_LENGHT];
    char string[MAX_LENGHT];
    lista_palavras= NULL;
    char **aux_lista_palavras= NULL;

    sprintf(formato,"%%%d",MAX_LENGHT-1);
    do{
        if((resultado = fscanf(filename,formato,string ))==1)
        {
            if(lista_palavras==NULL || (n_palavras%REALLOC_SIZE)==0) //fazer crescer o vetor de palavras
            {
              aux_lista_palavras= (char**)realloc(lista_palavras,(n_palavras+REALLOC_SIZE)*sizeof(char*));
                if(aux_lista_palavras==NULL)
                {
                    printf("Realloc falhou,ficheiro demasiado grande.");
                    liberta_lista_palavras(lista_palavras,n_palavras);
                    fclose(filename);
                    exit(EXIT_FAILURE);
                }else
                    lista_palavras= aux_lista_palavras;
            }
            if((lista_palavras[n_palavras]= (char*)malloc(strlen(string)+1))==NULL)//alocar a memória para a palavra
            {
                printf("malloc falhou,ficheiro demasiado grande.");
                liberta_lista_palavras(lista_palavras,n_palavras);
                fclose(filename);
                exit(EXIT_FAILURE);
            }
            strcpy(lista_palavras[n_palavras++],string);
        }
    }while(resultado != EOF);
    fclose(filename);
    printf("\nFicheiro lido.Existem %d palavras no ficheiro",n_palavras);


    return **lista_palavras;
}

/** \brief Funcao que recebe uma palavra e verifica s essa palavra existe no dicionario pretendido
 *
 * \param
 *      INPUT:Palavra a procurar(char)
 *      INPUT:array de strings alocada dinamicamente com o dicionario(char)
 *      OUTPUT:'1' se a palavra esta no dicionario,'0' se nao está
 *
 */

void validword(char *word,char *lista_palavras[]){


}
