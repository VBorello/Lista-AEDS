#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPercentual de Pares lidos entre 1000 e 10000\n");
}

float lerTermos(){

    int termos, total, contador = 0, pares = 0;
    while (termos != 0){
        printf("\nDigite o %d termo (0 para sair): ", contador + 1);
        scanf("%d", &termos);
        total += termos;

        if(termos % 2 == 0 && termos != 0 && termos >= 1000 && termos <= 10000){
            pares++;
        }
        if(termos != 0){
            contador++;
        }
    }

    float percentualPar = (float)pares / contador * 100;
    
    return percentualPar;
}

int main(){
    apresentacao();
    float percentual;
    percentual = lerTermos();

    printf("\nO percentual de numeros pares entre 1000 e 10000 e: %.2f%%", percentual);

    return 0;
}