#include <stdio.h>
#include <stdlib.h>

void apresentaco(){
    printf("\nE a potencia não tem como!\n\n");
}

int lerBase(){
    int base;
    printf("Digite a base: ");
    scanf("%d", &base);
    return base;
}

int expoente(){
    int exp;
    printf("Digite o expoente: ");
    scanf("%d", &exp);
    return exp;
}

int calcularPow(int n, int exp){
    int potencia;
    for(int i = 0; i < exp; i++){
        potencia = n * n;
    }

    return potencia;
}


int main(){
    apresentaco();

    int base = lerBase();
    int exp = expoente();
    int potencia = calcularPow(base, exp); 

    printf("\na potencia %d como base e %d como expoente e igual a: %d", base, exp, potencia);

    return 0;
}