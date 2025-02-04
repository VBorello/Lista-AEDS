#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nDobro da variavela alocada\n\n");
}

void lerN(int* n){
    printf("Digite o valor: ");
    scanf("%d", n);
}

void dobrar(int n, int* dobro){
    *dobro = n * 2;
}


int main(){
    apresentacao();
    
    int* dobro = (int *)malloc(sizeof(int));
    int* n = (int *)malloc(sizeof(int));
    
    lerN(n);
    dobrar(*n, dobro);

    printf("\nO dobro de %d e %d", *n, *dobro);


    free(dobro);
    free(n);

    return 0;
}