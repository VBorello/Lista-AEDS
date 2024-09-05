#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nRestruturar Politicas de preços\n\n");
}

void lerQtdMercadorias(int* qtd){
    printf("Digite a quantidade de mercadorias: ");
    scanf("%d", qtd);
}

void lerMercadorias(int* mercadorias, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("Digite a mercadoria %d: ", i + 1);
        scanf("%d", &mercadorias[i]);
    }
}

void maiorDosMenor(int* mercadorias, int qtd){
    int maior = 0;
    for(int i = 0; i < qtd; i++){
        if(mercadorias[i] < 2000 && mercadorias[i] > maior){
            maior = mercadorias[i];
        }
    }

    printf("\nA mercadoria com o maior valor abaixo de 2000$ e: %d", maior);
}

void menorDosMaior(int* mercadorias, int qtd){
    int menor = 100000;
    for(int i = 0; i < qtd; i++){
        if(mercadorias[i] > 2000 && mercadorias[i] < menor){
            menor = mercadorias[i];
        }
    }

    printf("\nA mercadoria com o menor valor acima de 2000$ e: %d", menor);
}

int main(){
    apresentacao();

    int quantidade;
    lerQtdMercadorias(&quantidade);
    int* mercadorias = (int *)malloc(quantidade * sizeof(int));
    
    lerMercadorias(mercadorias, quantidade);

    maiorDosMenor(mercadorias, quantidade);
    menorDosMaior(mercadorias, quantidade);

    free(mercadorias);
}