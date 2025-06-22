#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = '0';
}

void posicionarNavio(int navio[3][2]) {
    int orientacao = rand() % 2; // 0 = horizontal, 1 = vertical
    int linha, coluna;

    if (orientacao == 0) {
        linha = rand() % TAM;
        coluna = rand() % (TAM - 2);
        for (int i = 0; i < 3; i++) {
            navio[i][0] = linha;
            navio[i][1] = coluna + i;
        }
    } else {
        linha = rand() % (TAM - 2);
        coluna = rand() % TAM;
        for (int i = 0; i < 3; i++) {
            navio[i][0] = linha + i;
            navio[i][1] = coluna;
        }
    }
}

int verificarAcerto(int navio[3][2], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (navio[i][0] == linha && navio[i][1] == coluna)
            return 1;
    }
    return 0;
}

void mostrarTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n   ");
    for (int i = 0; i < TAM; i++) printf("%2d", i);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%2c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int navio[3][2], linha, coluna, acertos = 0, tentativas = 0;

    srand(time(NULL));
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(navio);

    printf("=== BATALHA NAVAL 10x10 ===\n");

    while (acertos < 3) {
        mostrarTabuleiro(tabuleiro);
        printf("Digite linha e coluna (0 a %d): ", TAM - 1);
        scanf("%d%d", &linha, &coluna);
        tentativas++;

        if (tabuleiro[linha][coluna] == '*' || tabuleiro[linha][coluna] == '3') {
            printf(">> Já tentou aqui!\n");
            continue;
        }

        if (verificarAcerto(navio, linha, coluna)) {
            printf(">> BOOM! Acertou parte do navio!\n");
            tabuleiro[linha][coluna] = '3';
            acertos++;
        } else {
            printf(">> Água!\n");
            tabuleiro[linha][coluna] = '*';
        }
    }

    mostrarTabuleiro(tabuleiro);
    printf("Parabéns! Você afundou o navio em %d tentativas!\n", tentativas);

    return 0;
}
