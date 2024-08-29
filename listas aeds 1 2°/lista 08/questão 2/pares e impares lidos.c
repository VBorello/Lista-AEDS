#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nContador de impares e pares de um vetor\n\n");
}

void termos(int* qtd){
    printf("Quantos numeros são: ");
    scanf("%d", qtd);
}

void lerNs(int* IP, int qtd){

    for(int i = 0; i < qtd; i++){
        printf("\nDigite o %d° termo: ", i + 1);
        scanf("%d", &IP[i]);
    }
}

void identificador(int* IP, int qtd, int* pares, int* impares){
    
    *pares = 0;
    *impares = 0;

    printf("\nPares do vetor: ");
    for(int i = 0; i < qtd; i++){
        if(IP[i] % 2 == 0){
            (*pares)++;
            printf("%d ", IP[i]);
        }
    }
    printf("\n%d pares no total\n", *pares);

    printf("\nImpares do vetor: ");
    for(int i = 0; i < qtd; i++){
        if(IP[i] % 2 != 0){
            (*impares)++;
            printf("%d ", IP[i]);
        }
    }
    printf("\n%d impares no total\n", *impares);
}


int main(){
    apresentacao();

    int qtd;
    int pares, impares;
    termos(&qtd);

    int* IP = (int *)malloc(qtd * sizeof(int));

    if(IP == NULL){
        printf("ERRO AO ALOCAR");
        return 1;
    }

    lerNs(IP, qtd);

    identificador(IP, qtd, &pares, &impares);


    free(IP);

    return 0;
}