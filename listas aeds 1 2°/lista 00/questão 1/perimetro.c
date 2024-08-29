#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\ncalcular perimetro de um quadrado\n\n");
}

void lerLado(int*lado){

    printf("Digite o valor do lado:");
    scanf("%d", lado);
}

int calcularPerimetro(int lado){
    
    int perimetro;
    perimetro = lado * 4;

    return perimetro;
}

int main(){

    int lado;
    lerLado(&lado);
    int perimetro = calcularPerimetro(lado);
    
    printf("\nO valor do perimetro do quadrado e: %d", perimetro);

    return 0;
}