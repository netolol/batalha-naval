#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5

void mostrarTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("[%d]", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void habilidadeCone(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS)
        tabuleiro[linha][coluna] = 9;

    if (linha-1 >= 0 && coluna-1 >= 0)
        tabuleiro[linha-1][coluna-1] = 9;
    if (linha-1 >= 0 && coluna+1 < COLUNAS)
        tabuleiro[linha-1][coluna+1] = 9;
}

void habilidadeCruz(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS)
        tabuleiro[linha][coluna] = 9;

    if (linha-1 >= 0)
        tabuleiro[linha-1][coluna] = 9;
    if (linha+1 < LINHAS)
        tabuleiro[linha+1][coluna] = 9;
    if (coluna-1 >= 0)
        tabuleiro[linha][coluna-1] = 9;
    if (coluna+1 < COLUNAS)
        tabuleiro[linha][coluna+1] = 9;
}

void habilidadeOctaedro(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    for (int i = linha-1; i <= linha+1; i++) {
        for (int j = coluna-1; j <= coluna+1; j++) {
            if (i >= 0 && i < LINHAS && j >= 0 && j < COLUNAS)
                tabuleiro[i][j] = 9;
        }
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};
    int opcao, linha, coluna;

    printf("Bem-vindo ao Batalha Naval - Módulo Mestre!\n");

    while (1) {
        mostrarTabuleiro(tabuleiro);

        printf("\nEscolha uma habilidade:\n");
        printf("1. Cone\n2. Cruz\n3. Octaedro\n0. Sair\n");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("Informe a linha e a coluna da célula central (0 a %d): ", LINHAS-1);
        scanf("%d %d", &linha, &coluna);

        switch (opcao) {
            case 1:
                habilidadeCone(tabuleiro, linha, coluna);
                break;
            case 2:
                habilidadeCruz(tabuleiro, linha, coluna);
                break;
            case 3:
                habilidadeOctaedro(tabuleiro, linha, coluna);
                break;
            default:
                printf("Opção inválida!\n");
        }
    }

    printf("\nTabuleiro final:");
    mostrarTabuleiro(tabuleiro);

    return 0;
}
