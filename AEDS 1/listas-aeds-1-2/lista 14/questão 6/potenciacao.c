#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nPotenciacao recursiva\n\n");
}

void lerBase(int* base){
    printf("digite a base: ");
    scanf("%d", base);
}

void lerExpoente(int* expoente){
    printf("digite a base: ");
    scanf("%d", expoente);
}

int calcularPotencia(int base, int expoente){

    int potencia;
    if(expoente < 0){
        potencia = 0;
    }
    else if(expoente == 0){
        potencia = 1;
    }
    else{
        potencia = base * calcularPotencia(base, expoente - 1);
    }

    return potencia;
}

int main(){
    apresentacao();
    int base, expoente, potencia;

    lerBase(&base);
    lerExpoente(&expoente);

    potencia = calcularPotencia(base, expoente); 

    printf("%d^%d: %d", base, expoente, potencia);

    return 0;
}