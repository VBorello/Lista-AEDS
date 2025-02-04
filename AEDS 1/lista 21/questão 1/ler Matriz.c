#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nFuncao ler e print matriz\n\n");
}

int tamanhoMatriz() {
    int tamanho;
    printf("Qual o tamanho da matriz? ");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerMatriz(int** m, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void printMatriz(int** m, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    apresentacao();

    int tamanho = tamanhoMatriz();

    int** m = (int**)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        m[i] = (int*)malloc(tamanho * sizeof(int));
    }

    lerMatriz(m, tamanho);
    printMatriz(m, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}
