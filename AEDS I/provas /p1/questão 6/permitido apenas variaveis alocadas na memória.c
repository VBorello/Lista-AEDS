#include <stdio.h>
#include <stdlib.h>

void apresetancao(){
    printf("\nPerimetro De um Quadrado Alocado na memória\n\n");
}

void lerLado(int* lado){
    printf("Digite o lado do quadrado: ");
    scanf("%d", lado);
}

void calularPerimetro(int lado, int* perimetro){
    *perimetro = lado * 4;

    printf("\nO perimetro do quadrado de lado %d e: %d", lado, *perimetro);
}

int main(){
    apresetancao();

    int* lado = (int *)malloc(sizeof(int));
    int* perimetro = (int *)malloc(sizeof(int));
    lerLado(lado);
    
    calularPerimetro(*lado, perimetro);

    free(lado);
    free(perimetro);

    return 0;
}