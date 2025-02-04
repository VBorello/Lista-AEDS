#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nTroca Maior Valor para ultima posição de um vetor\n\n");
}

void lerTam(int* tam){
    printf("Digite o tamanho do vetor: ");
    scanf("%d", tam);
}

void lerVetor(int tam, int vetor[tam]){

    for(int i = 0; i < tam; i++){
        printf("\nDigite o %d termo do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int pegarMaior(int tam, int vetor[tam]){
    
    int maior = 0;

    for(int i = 0; i < tam; i++){
        if(vetor[i] > vetor[maior]){
            maior = i;
        }
    }

    return maior;
}

void trocarPMaior(int tam, int maior, int vetor[tam]){
    
    printf("\nAntes: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    int aux = vetor[maior];

    vetor[maior] = vetor[tam -1];
    vetor[tam - 1] =  aux;

    printf("\nDepois: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){
    apresentacao();


    int tam;
    lerTam(&tam);

    int* vetor = (int *)malloc(tam * sizeof(int));
    lerVetor(tam, vetor);

    int maior = pegarMaior(tam, vetor);

    trocarPMaior(tam, maior, vetor);


    free(vetor);

    return 0 ;
}