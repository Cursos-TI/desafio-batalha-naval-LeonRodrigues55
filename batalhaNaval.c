#include <stdio.h>

int main() {
    int tamanho = 10;
    int tamanhoNavio = 3;
    int tabuleiro[10][10];

    //Logica do tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //Navio 1: Horizontal
    int l1 = 2, c1 = 3;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[l1][c1 + i] = 3;
    }

    //Navio 2: Vertical
    int l2 = 5, c2 = 1;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[l2 + i][c2] = 3;
    }

    //Navio 3: Diagonal esquerdo
    int l3 = 0, c3 = 0;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[l3 + i][c3 + i] = 3;
    }

    //Navio 4: Diagonal direito
    int l4 = 0, c4 = tamanho - 1;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[l4 + i][c4 - i] = 3;
    }

    //Habilidades
    int tamHab = 5;
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    //Preencher Cone
    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            if (j >= (tamHab / 2 - i) && j <= (tamHab / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    //Preencher Cruz
    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            if (i == tamHab / 2 || j == tamHab / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    //Preencher Octaedro
    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            if (abs(i - tamHab / 2) + abs(j - tamHab / 2) <= tamHab / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Origem das habilidades no tabuleiro
    int origemConeL = 4, origemConeC = 4;
    int origemCruzL = 1, origemCruzC = 8;
    int origemOctL = 7, origemOctC = 5;

    // Função genérica para aplicar habilidade
    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            int li = origemConeL + i - tamHab / 2;
            int co = origemConeC + j - tamHab / 2;
            if (li >= 0 && li < tamanho && co >= 0 && co < tamanho) {
                if (cone[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }

    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            int li = origemCruzL + i - tamHab / 2;
            int co = origemCruzC + j - tamHab / 2;
            if (li >= 0 && li < tamanho && co >= 0 && co < tamanho) {
                if (cruz[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }

    for (int i = 0; i < tamHab; i++) {
        for (int j = 0; j < tamHab; j++) {
            int li = origemOctL + i - tamHab / 2;
            int co = origemOctC + j - tamHab / 2;
            if (li >= 0 && li < tamanho && co >= 0 && co < tamanho) {
                if (octaedro[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }

    //Tabuleiro na tela
    printf("   TABULEIRO BATALHA NAVAL\n\n   ");
    for (int letra = 0; letra < tamanho; letra++) {
        printf(" %c", 'A' + letra);
    }
    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < tamanho; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~"); // Água
            else if (tabuleiro[i][j] == 3)
                printf(" N"); // Navio
            else if (tabuleiro[i][j] == 5)
                printf(" *"); // Área habilidade
        }
        printf("\n");
    }

    return 0;
}
