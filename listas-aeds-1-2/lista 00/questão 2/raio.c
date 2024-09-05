#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nCalculador de area de um circulo\n\n");
}

void lerRaio(int* raio){

    printf("digite o valor do raio do circulo:");
    scanf("%d", raio);
}

int calcularArea(int raio){

    int area;
    area = raio * raio;

    return area;
}

int main(){

    int raio;
    lerRaio(&raio);
    int area = calcularArea(raio);
    printf("\nA area do circulo e: %d", area);

    return 0;
    
}