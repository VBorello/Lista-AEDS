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

void inverterV(int v[], int tamanho) {
    for (int i = 0; i < tamanho / 2; i++) {
        int temp = v[i];
        v[i] = v[tamanho - 1 - i];
        v[tamanho - 1 - i] = temp;
    }
}

void imprimirV(int v[], int tamanho) {
    printf("Vetor invertido:\n");
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
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    lerV(v, tamanho);
    inverterV(v, tamanho);
    imprimirV(v, tamanho);

    free(v);

    return 0;
}
