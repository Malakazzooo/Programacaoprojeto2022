#include "headers.h"
#include "help.h"


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
