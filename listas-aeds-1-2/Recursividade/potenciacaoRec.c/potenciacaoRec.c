#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nPotenciacao recursiva\n\n");
}

void lerBase(float* base){
    printf("Digite a base: ");
    scanf("%f", base);
}

void lerExpoente(int* expoente){
    printf("\nDigite o expoente: ");
    scanf("%d", expoente);
}

float calcularPotenciacaoRec(float base, int expoente){
    
    float potencia;
    if(expoente < 0){
        potencia = 0;
    }
    else if(expoente == 0){
        potencia = 1;
    }
    else{
        potencia = base * calcularPotenciacaoRec(base, expoente - 1);
    }

    return potencia;
}

int main(){
    apresentacao();

    float base;
    lerBase(&base);
    int expoente;
    lerExpoente(&expoente);

    float potencia = calcularPotenciacaoRec(base, expoente);

    printf("\n%.0f^%d = %.2f\n", base, expoente, potencia);
    
    return 0;
}