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

bool verificarInversoRec(int* v1, int* v2, int inicio, int fim) {
    
    if (inicio >= fim) {
        return true;
    }

    if (v1[inicio] != v2[fim]) {
        return false;
    }

    return verificarInversoRec(v1, v2, inicio + 1, fim - 1);
}



int main(){
    apresentacao();

     apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int* v1 = (int*)malloc(tamanho * sizeof(int));
    int* v2 = (int*)malloc(tamanho * sizeof(int));

    lerVetor(tamanho, v1, v2);

    if (verificarInversoRec(v1, v2, 0,tamanho - 1)) {
        printf("\nO segundo vetor é o inverso do primeiro\n");
    } else {
        printf("\nO segundo vetor NÃO é o inverso do primeiro\n");
    }

    free(v1);
    free(v2);

    return 0;
}