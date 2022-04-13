#include "headers.h"

#include "gamemode.h"

#include "board.h"

#include "word.h"

#include "help.h"

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

void validword(char word[MAX_LENGHT],char *lista_palavras[]);
void Error(int i);
void help();



 int main(int argc,char *argv[])
{
    int board[15][15]={0};
    int linhas=15,colunas=15;
    int option=0;
    int gamemode=1; //predefinicao de modo de jogo
    char **lista_palavras;
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
       loaddic(infile,lista_palavras);
    }
    //abrir o ficheiro de saida
    if(outfile)
    {
        printf("\n*A abrir o ficheiro %s *\n", outfile);
        if ((fpout= fopen(outfile, "r"))==NULL)
        {
            printf("Não consegui abrir o ficheirod de saida.\n");
            exit(-1);
        }
    }

    //loaddic(fp,char *palavras);



    //*********************ficheiros************************


    //if(gamemode==1){gamemode1(board,linhas);}





    return 0;

}




