#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool compararMatrizes(int** m1, int** m2, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (m1[i][j] != m2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void copiarMatriz(int** m1, int** m2, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            m2[i][j] = m1[i][j];
        }
    }
}

void transporMatriz(int** m1, int** m2, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            m2[j][i] = m1[i][j];
        }
    }

    printf("\nMatriz Transposta:\n");
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", m2[i][j]);
        }
        printf("\n");
    }
}

int main() {
    apresentacao();

    int tamanho = tamanhoMatriz();

    int** m1 = (int**)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        m1[i] = (int*)malloc(tamanho * sizeof(int));
    }

    printf("\nLeitura da matriz 1:\n");
    lerMatriz(m1, tamanho);

    int** m2 = (int**)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        m2[i] = (int*)malloc(tamanho * sizeof(int));
    }

    printf("\nLeitura da matriz 2:\n");
    lerMatriz(m2, tamanho);

    printf("\nMatriz 1:\n");
    printMatriz(m1, tamanho);

    printf("\nMatriz 2:\n");
    printMatriz(m2, tamanho);

    if (compararMatrizes(m1, m2, tamanho)) {
        printf("\nAs matrizes são iguais.\n");
    } else {
        printf("\nAs matrizes não são iguais.\n");
    }

    int** matrizCopia = (int**)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        matrizCopia[i] = (int*)malloc(tamanho * sizeof(int));
    }
    copiarMatriz(m1, matrizCopia, tamanho);

    printf("\nCopia:\n");
    printMatriz(matrizCopia, tamanho);

    transporMatriz(m1, m2, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(m1[i]);
        free(m2[i]);
        free(matrizCopia[i]);
    }
    free(m1);
    free(m2);
    free(matrizCopia);

    return 0;
}
