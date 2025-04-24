#include <stdio.h>

#define TAMANHO 10

int main() {
    int tabuleiro[TAMANHO] = {0}; // Inicializa tudo com 0 (água)
    int numNavios, pos;

    printf("Bem-vindo ao Batalha Naval - Módulo Novato!\n");
    printf("Quantos navios deseja posicionar? ");
    scanf("%d", &numNavios);

    for(int i = 0; i < numNavios; i++) {
        printf("Digite a posição do navio %d (0 a %d): ", i + 1, TAMANHO - 1);
        scanf("%d", &pos);

        if(pos >= 0 && pos < TAMANHO) {
            if(tabuleiro[pos] == 0) {
                tabuleiro[pos] = 1;
            } else {
                printf("Já existe um navio nessa posição! Tente novamente.\n");
                i--; // força o jogador a repetir essa tentativa
            }
        } else {
            printf("Posição inválida! Tente novamente.\n");
            i--;
        }
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    for(int i = 0; i < TAMANHO; i++) {
        printf("[%d]", tabuleiro[i]);
    }
    printf("\n");

    return 0;
}
