#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nIdentificador de triangulo\n\n");
}

void lerLados(int* lado1,int* lado2, int* lado3){
    
    printf("Digite os tres lados de maneira espaçada:");
    scanf("%d %d %d", lado1, lado2, lado3);
}

void identificadorDeTriangulo(int* lado1,int* lado2, int* lado3){

    if(lado1 != lado2 && lado2 != lado3 && lado1 != lado3){
        printf("\nO triangulo é escaleno");
    }
    else if(lado1 == lado2 && lado1 == lado3 && lado2 == lado3){
        printf("\nO triangulo é equilátero");
    }
    else if(lado1 == lado2 && lado1 != lado3 && lado2 != lado3 ||
                lado1 == lado3 && lado1 != lado2 && lado3 != lado2 ||
                    lado2 == lado3 && lado2 != lado1 && lado3 != lado1){
                        printf("\nO triangulo é isóceles");
    }
}



int main(){

    apresentacao();
    int lado1, lado2, lado3;

    lerLados(&lado1, &lado2, &lado3);
    identificadorDeTriangulo(lado1, lado2, lado3);

    return 0;
}