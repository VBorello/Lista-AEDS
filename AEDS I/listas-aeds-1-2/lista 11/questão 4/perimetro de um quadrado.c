#include<stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nPerimetro de um quadrado funcao\n\n");
}

int lerLado(){
    int lado;
    printf("Digite o valor do lado: ");
    scanf("%d", &lado);
    return lado;
}

int calcularPerimetro(int lado){
    int perimetro = lado *4;

    return perimetro;
}

int main(){
    apresentacao();
    int lado = lerLado();
    int perimetro = calcularPerimetro(lado);

    printf("O valor do perimetro de um quadrado de lado %d e: %d", lado, perimetro);
    
    return 0;
}