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

    //Tabuleiro na tela
    printf("   TABULEIRO BATALHA NAVAL\n\n   ");
    for (int letra = 0; letra < tamanho; letra++) {
        printf(" %c", 'A' + letra);
    }
    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < tamanho; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}