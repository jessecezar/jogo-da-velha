#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void Tabuleiro(char casas2[9],char jogador1[20],char jogador2[20], int p1, int p2){
    system("cls");
    printf("\n");
    printf("    %c | %c | %c       Placar\n", casas2[0], casas2[1], casas2[2]);
    printf("   -----------      %s: %d\n", jogador1, p1);
    printf("    %c | %c | %c       %s: %d\n", casas2[3], casas2[4], casas2[5], jogador2, p2);
    printf("   -----------            \n");
    printf("    %c | %c | %c          \n", casas2[6], casas2[7], casas2[8]);
}

int main(){
    system("cls");
    setlocale(LC_ALL,"Portuguese");

    char casas[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char jogador_X[20], jogador_O[20];
    int cont_jogadas, resposta, jogada, vez = 0, i, pontos_X = 0, pontos_O = 0, X = 0, O = 0;

    printf("Informe o nome do primeiro jogador: ");
    fflush(stdin);
    gets(jogador_X);
    
    printf("Informe o nome do segundo jogador: ");
    fflush(stdin);
    gets(jogador_O);
    
    do {
        cont_jogadas = 1;
        for (i = 0; i < 9; i++){
            casas[i] = ' ';
        }
        
        do {
            Tabuleiro(casas, jogador_X, jogador_O, pontos_X, pontos_O);
            if (vez%2 == 0){
                printf("\nVez de %s \n", jogador_X);
            } else {
                printf("\nVez de %s \n", jogador_O);
            }
            printf("\nDigite a casa desejada [1-9]\n");
            scanf("%d", &jogada);

            if (jogada < 1 || jogada > 9){
                printf("Opção Inválida!!!");
                jogada = 0;
            }else if (casas[jogada-1] != ' '){
                jogada = 0;
            }else {
                if (vez%2 == 0){
                    casas[jogada-1] = 'X';
                }else {
                    casas[jogada-1] = 'O';
                }
                cont_jogadas++;
                vez++;
            }
            if (casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X'){cont_jogadas = 11;}
            if (casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){cont_jogadas = 11;}
            if (casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
            if (casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}
            if (casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X'){cont_jogadas = 11;}
            if (casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
            if (casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}
            if (casas[2] == 'X' && casas[4] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}

            if (casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O'){cont_jogadas = 12;}
            if (casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O'){cont_jogadas = 12;}
            if (casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}
            if (casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O'){cont_jogadas = 12;}
            if (casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O'){cont_jogadas = 12;}
            if (casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}
            if (casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}
            if (casas[2] == 'O' && casas[4] == 'O' && casas[6] == 'O'){cont_jogadas = 12;}
            
        } while (cont_jogadas <= 9);
        Tabuleiro(casas, jogador_X, jogador_O, pontos_X, pontos_O);
        X = pontos_X;
        O = pontos_O;

        if (cont_jogadas == 10){
            printf("\nJogo empatado");
        }else if (cont_jogadas == 11){
            printf("\n%s Venceu!!!!\n", jogador_X);
            pontos_X++;
        }else if (cont_jogadas == 12){
            printf("\n%s Venceu!!!!\n", jogador_O);
            pontos_O++;
        }

        if (pontos_X > X){
            vez = 0;
        }
        if (pontos_O > O){
            vez = 1;
        }

        printf("\nDeseja jogar novamente? [1- Sim  2- Não]\n");
        scanf("%d", &resposta);
    } while (resposta == 1);

    return 0;
}