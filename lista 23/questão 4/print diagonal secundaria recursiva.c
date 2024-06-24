#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nEscrever os valores da diagonal secundária de uma matriz\n\n");
}

int lerTamanho() {
    int tamanho;
    printf("Qual o tamanho da matriz?: ");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerM(int **m, int tamanho) { 
    for(int i = 0; i < tamanho; i++) { 
        for(int j = 0; j < tamanho; j++) { 
            printf("m[%d][%d]: ", i + 1, j + 1); 
            scanf("%d", &m[i][j]); 
        } 
    }
}

void printDiagonalSec(int **m, int tamanho, int indice) {
    if (indice < 0) {
        return; 
    }

    printf("%d ", m[indice][tamanho - 1 - indice]);

    printDiagonalSec(m, tamanho, indice - 1); 
}

int main() {
    apresentacao();
    
    int tamanho = lerTamanho();

    int **m1 = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        m1[i] = (int *)malloc(tamanho * sizeof(int));
    }

    lerM(m1, tamanho);  
 
    printf("\nm1\n"); 
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }

    printf("Diagonal secundaria: ");
    printDiagonalSec(m1, tamanho, tamanho - 1);
    printf("\n");

    for (int i = 0; i < tamanho; i++) {
        free(m1[i]);
    }
    free(m1);

    return 0;
}
