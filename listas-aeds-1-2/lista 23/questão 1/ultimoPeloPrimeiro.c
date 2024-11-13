#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    system("clear");
    printf("\nTroca do Primeiro Termo pelo Ultimo de um Vetor\n\n");
}

void lerTam(int *tam){
    printf("Digite o tamanho do vetor:");
    scanf("%d", tam);
}

void preencherVetor(int tam, float vetor[tam]){
    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor %d do vetor: ", i + 1);
        scanf("%f", &vetor[i]);
    }
}

void trocaTermos(int tam, float vetor[tam]){
    
    printf("antes: ");
    for(int i = 0; i < tam; i++){
        printf("%.1f ", vetor[i]);
    }
    printf("\n");

    float primeiro = vetor[0];
    vetor[0] = vetor[tam - 1];
    vetor[tam - 1] = primeiro;

    printf("\nDepois: ");
    for(int i = 0; i < tam; i++){
        printf("%.1f ", vetor[i]);
    }
    printf("\n");
}

int main(){
    apresentacao();

    int tamanho;
    lerTam(&tamanho);

    float *vetor = (float *)malloc(tamanho * sizeof(float));

    preencherVetor(tamanho, vetor);

    trocaTermos(tamanho, vetor);


    free(vetor);

    return 0;
}
