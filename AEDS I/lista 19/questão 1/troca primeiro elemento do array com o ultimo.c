#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nTroca Primeiro termo do array pelo ultimo.\n\n");
}

int lerTamanho(){
    int tamanho;
    printf("Digite o tamanho do array:");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerArranjo(int v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %d termo: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void trocaPrimeiroPorUltimo(int v[], int tamanho) {
    if (tamanho > 1) {
        int aux = v[0];
        v[0] = v[tamanho - 1];
        v[tamanho - 1] = aux;
    }
}

int main() {
    apresentacao();

    int comprimento = lerTamanho();
    if (comprimento <= 0) {
        printf("O tamanho do array deve ser um número positivo.\n");
        return 1;
    }

    int v[comprimento];  

    lerArranjo(v, comprimento);
    trocaPrimeiroPorUltimo(v, comprimento);

    printf("Array modificado:\n");
    for (int i = 0; i < comprimento; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
