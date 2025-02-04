#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSeparar A parte Real Do Inteiro\n\n");
}

void separar(float numero, float parteRal, int parteInteira){

    printf("Digite um numero(real): ");
    scanf("%f", &numero);


    parteInteira = (int)numero;
    parteRal = numero - parteInteira;

    printf("\nA parte inteira de %f é: %d e a parte real é: %f", numero, parteInteira, parteRal);
}


int main(){
    apresentacao();

    int numero, parteInteira;
    float parteReal;


    separar(numero, parteReal, parteInteira);

    return 0;
}