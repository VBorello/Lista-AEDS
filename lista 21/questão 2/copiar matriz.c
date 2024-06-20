#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nCopiar matriz 1 em uma segunda\n\n");
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

void copiarMatriz(int** m1, int** m2, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            m2[i][j] = m1[i][j];
        }
    }
}

int main() {
    apresentacao();

    int tamanho = tamanhoMatriz();

    int** matrizOriginal = (int**)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        matrizOriginal[i] = (int*)malloc(tamanho * sizeof(int));
    }

    lerMatriz(matrizOriginal, tamanho);
    
    int** matrizCopia = (int**)malloc(tamanho * sizeof(int*));
    for (int i = 0; i < tamanho; i++) {
        matrizCopia[i] = (int*)malloc(tamanho * sizeof(int));
    }

    copiarMatriz(matrizOriginal, matrizCopia, tamanho);

    printf("\nM1:\n");
    printMatriz(matrizOriginal, tamanho);

    printf("\nM2:\n");
    printMatriz(matrizCopia, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(matrizOriginal[i]);
        free(matrizCopia[i]);
    }
    free(matrizOriginal);
    free(matrizCopia);

    return 0;
}
