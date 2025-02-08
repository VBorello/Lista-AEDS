#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nQuantidade acima da media do vetor\n\n");
}

void pegarTamain(int *tamain){
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", tamain);
}

void lerVetor(int tam, int v[tam]){
   
    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor %d do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void mediaVetor(int tam, int v[tam]){

    int soma = 0;
    int total = 0;
    for(int i = 0; i < tam; i++){
        soma += v[i];
        total++;
    }

    float media = (float)soma / total;

    int acima = 0;
    for(int i = 0; i < tam; i++){
        if(v[i] > media){
            acima++;
        }
    } 

    printf("\nA media do vetor é: %.0f", media);
    printf("\nSão %d os valores acima da media do vetor.", acima);
}

int main(){
    apresentacao();

    int tamanho;
    pegarTamain(&tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    lerVetor(tamanho, vetor);
    mediaVetor(tamanho, vetor);

    free(vetor);
    return 0;
}