#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};
    int numNavios, linha, coluna;

    printf("Bem-vindo ao Batalha Naval - Módulo Aventureiro!\n");
    printf("Quantos navios deseja posicionar? ");
    scanf("%d", &numNavios);

    for (int i = 0; i < numNavios; i++) {
        printf("Digite a linha e coluna do navio %d (0 a %d): ", i + 1, LINHAS - 1);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS) {
            if (tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 1;
            } else {
                printf("Já existe um navio nessa posição! Tente novamente.\n");
                i--;
            }
        } else {
            printf("Posição inválida! Tente novamente.\n");
            i--;
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("[%d]", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
