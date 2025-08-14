#include <stdio.h>

int main() {
    int tamanho = 10;
    int tamanhoNavio = 3;

    int tabuleiro[10][10];
    int navio1[3] = {3, 3, 3}; //horizontal
    int navio2[3] = {3, 3, 3}; //vertical

    //Logica do tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //Navios no tabuleiro
    int linhaNavio1 = 1; 
    int colunaNavio1 = 3; 

    int linhaNavio2 = 5; 
    int colunaNavio2 = 1; 

    //pocição do navio 1 (horizontal)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavio1][colunaNavio1 + i] = navio1[i];
    }

    //pocição do navio 2 (vertical)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaNavio2 + i][colunaNavio2] = navio2[i];
    }

    //Mensagem inicial junto com as letras horizontais (coordenadas)
    printf("****TABULEIRO BATALHA NAVAL\n\n****");
    for (int letra = 0; letra < tamanho; letra++) {
        printf(" %c", 'A' + letra);
    }
    printf("\n");

    //Números na vertical (coordenadas)
    for (int i = 0; i < tamanho; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < tamanho; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
