#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nInvertedor de vetor\n\n");
}

void lerV(int v[], int tamanho) {
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &v[i]);
    }
}

void inverterVRecursivo(int v[], int inicio, int fim) {
    if (inicio >= fim) {
        return;
    }
    int aux = v[inicio];
    v[inicio] = v[fim];
    v[fim] = aux;
    inverterVRecursivo(v, inicio + 1, fim - 1);
}

void inverterV(int v[], int tamanho) {
    inverterVRecursivo(v, 0, tamanho - 1);
}

void printV(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    apresentacao();

    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int* v = (int*)malloc(tamanho * sizeof(int));
    if (v == NULL) {
        printf("ERRO ao alocar\n");
        return 1;
    }

    lerV(v, tamanho);
    inverterV(v, tamanho);
    printV(v, tamanho);

    free(v);  
    return 0;
}
