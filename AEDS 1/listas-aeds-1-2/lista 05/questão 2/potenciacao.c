#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPotenciacao\n\n");
}

void lerN(int* n){
    printf("Digite o numero:");
    scanf("%d", n);

}

void lerExpoente(int* exp){
    bool erro;

    do{
        printf("\nDigite o expoente:");
        scanf("%d", exp);
        
        erro = (exp < 0);
        if(erro){
            printf("\nexpoente inváldo");
        }
    }while(erro);
}

int calcularPow(int n, int exp){

    int resultado = 1;

    for(int i = 0; i < exp; i++){
        resultado *= n;
    }

    return resultado;
}

int main(){

    apresentacao();

    int n;
    int expoente;
    lerN(& n);
    lerExpoente(& expoente);

    int resultado = calcularPow(n, expoente);

    printf("\no resultado da potenciacao deu: %d", resultado);

    return 0;
}