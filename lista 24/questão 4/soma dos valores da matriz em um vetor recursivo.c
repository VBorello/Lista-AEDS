#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSoma dos Valores na Matriz recursiva\n\n");
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

void somaColRec(int **m, int *v, int tamanho, int coluna) {
    if (coluna >= tamanho) {
        return;
    }

    v[coluna] = 0;

    somaColRec(m, v, tamanho, coluna + 1); 

    for (int i = 0; i < tamanho; i++) {
        v[coluna] += m[i][coluna];
    }
}

void printV(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    apresentacao();

    int tamanho = lerTamanho();

    int **m = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        m[i] = (int *)malloc(tamanho * sizeof(int));
    }

    lerM(m, tamanho);

    printM(m, tamanho);

    int *v = (int *)malloc(tamanho * sizeof(int));

    somaColRec(m, v, tamanho, 0);

    printf("Soma das colunas (recursiva): ");
    printV(v, tamanho);

    for (int i = 0; i < tamanho; i++) {
        free(m[i]);
    }
    free(m);
    free(v);

    return 0;
}
