#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nImpaOuPa\n\n");
}

void lerValor(int* valor){
    printf("digite qualquer valor:");
    scanf("%d", valor);
}

void mpaOuPa(int valor){
    
    if(valor % 2 == 0){
        printf("%d e par", valor);
    }
    else{
        printf("%d e impar", valor);
    }
}

int main(){

    apresentacao();
    float valor;
    lerValor(&valor);

    impaOuPa(valor);

    return 0;
}