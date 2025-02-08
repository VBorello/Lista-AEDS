#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool igualOuNao(float n1, float n2, float n3){
    
    bool igual = false;
    
    printf("\nDigite o valor 1: ");
    scanf("%f", &n1);

    printf("\nDigite o valor 1: ");
    scanf("%f", &n2);

    printf("\nDigite o valor 1: ");
    scanf("%f", &n3);

    if(n1 == n2 && n2 == n3){
        igual = true;
    }

    return igual;
}

int main(){
    float n1, n2, n3;

    if(igualOuNao(n1, n2, n3)){
        printf("\n Iguais");
    }
    else{
        printf("\n Diferentes");
    }

    return 0;
}