#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nTroca Menor Valor para primeira posição de um vetor\n\n");
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

int pegarMenor(int tam, int vetor[tam]){
    
    int menor = 0;

    for(int i = 0; i < tam; i++){
        if(vetor[i] < vetor[menor]){
            menor = i;
        }
    }

    return menor;
}

void trocarMenor(int tam, int menor, int vetor[tam]){
    
    printf("\nAntes: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    int aux = vetor[menor];

    vetor[menor] = vetor[0];
    vetor[0] =  aux;

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

    int menor = pegarMenor(tam, vetor);

    trocarMenor(tam, menor, vetor);


    free(vetor);

    return 0 ;
}