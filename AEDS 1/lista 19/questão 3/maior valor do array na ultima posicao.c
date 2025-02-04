#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nMaior valor do array na última posição\n\n");
}

int lerComprimento(){
    int comprimento;
    printf("Digite o tamanho do array: ");
    scanf("%d", &comprimento);
    return comprimento;
}

void lerArray(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite o %dº valor desse array: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void maiorNaUltimaPosicao(int v[], int tamanho){
    int maior = v[0];
    int ultimo = 0;

    for(int i = 0; i < tamanho; i++){
        if(v[i] > maior){
            maior = v[i];
            ultimo = i;
        }
    }

    int aux = v[tamanho - 1];
    v[tamanho - 1] = maior;
    v[ultimo] = aux;

    printf("Array com o maior valor trocado:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    apresentacao();

    int tamanho = lerComprimento();
    int* v = (int *)malloc(tamanho * sizeof(int));

    lerArray(v, tamanho);

    maiorNaUltimaPosicao(v, tamanho);

    free(v);
    return 0;
}