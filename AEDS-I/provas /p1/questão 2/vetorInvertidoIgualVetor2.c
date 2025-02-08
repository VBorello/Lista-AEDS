#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nVerificador de igualdade entre um vetor e outro invertido\n\n");
}

void lerTam(int* tam){
    printf("Qual o tamanho do vetor: ");
    scanf("%d", tam);
}

void lerVetor(int tam, int* v1, int* v2){

    printf("\nDigite o vetor 1: \n");
    for(int i = 0; i < tam; i++){
        printf("Digite o %d°: ", i + 1);
        scanf("%d", &v1[i]);
    }
    printf("\nDigite o vetor 2: \n");
    for(int i = 0; i < tam; i++){
        printf("Digite o %d°: ", i + 1);
        scanf("%d", &v2[i]);
    }
}

bool verificarInverso(int tam, int* v1, int* v2){
    
    for(int i = 0; i < tam; i++){
        if(v1[i] != v2[tam - 1 - i]){
            return false;
        }
    }
    return true;
}



int main(){
    apresentacao();

     apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int* v1 = (int*)malloc(tamanho * sizeof(int));
    int* v2 = (int*)malloc(tamanho * sizeof(int));

    lerVetor(tamanho, v1, v2);

    if (verificarInverso(tamanho, v1, v2)) {
        printf("\nO segundo vetor é o inverso do primeiro\n");
    } else {
        printf("\nO segundo vetor não é o inverso do primeiro\n");
    }

    free(v1);
    free(v2);

    return 0;
}