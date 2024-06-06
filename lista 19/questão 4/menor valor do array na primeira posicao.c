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
    int menor = v[0];
    int primeiro = 0;

    for(int i = 0; i < tamanho; i++){
        if(v[i] < primeiro){
            menor = v[i];
            primeiro = i;
        }
    }

    int aux = v[0 + 1];
    v[0 + 1] = menor;
    v[primeiro] = aux;

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