#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSoma dos Valores na Matriz \n\n");
}

int lerTamanho() {
    int tamanho;
    printf("Qual o tamanho da matriz?: ");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerM(int **m, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("m[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void printM(int **m, int tamanho) { 
    for (int i = 0; i < tamanho; i++) { 
        for (int j = 0; j < tamanho; j++) { 
            printf("%d ", m[i][j]); 
        } 
        printf("\n");
    } 
    printf("\n");
}

void somaCol(int **m, int *v, int tamanho) {
    for (int j = 0; j < tamanho; j++) {
        v[j] = 0;
        for (int i = 0; i < tamanho; i++) {
            v[j] += m[i][j];
        }
    }
}

void printV(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = lerTamanho();

    int **m = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        m[i] = (int *)malloc(tamanho * sizeof(int));
    }

    lerM(m, tamanho);

    printM(m, tamanho);

    int *v = (int *)malloc(tamanho * sizeof(int));
    somaCol(m, v, tamanho);

    printf("Soma das colunas (iterativa): ");
    printV(v, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(m[i]);
    }
    free(m);
    free(v);

    return 0;
}
