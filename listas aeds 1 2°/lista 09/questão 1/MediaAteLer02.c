#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nMedia de valores até 0\n");
}

int main(){
    apresentacao();
    int valores;
    int total, contador = 0;

    while(valores != 0){
        
        printf("\nDigite valores para saber a média(0 - para sair): ");
        scanf("%d", &valores);
        total += valores;
        if(valores != 0){
            contador++;
        }
    }   

    float media = (float)total / contador;
    printf("\n A media dos valores e: %.2f", media);

    return 0;
}