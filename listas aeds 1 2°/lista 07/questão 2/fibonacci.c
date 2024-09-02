#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nSequência de Fibonacci\n\n");

    int termos;
    printf("quantos termos da sequência quer ver? ");
    scanf("%d", &termos);


    int primeiro = 0, resultado;
    int segundo = primeiro + 1;

    printf("%d ", segundo);
    for(int i = 0; i < termos; i++){
        
        resultado = primeiro + segundo;
        primeiro = segundo;
        segundo = resultado;
        
        printf("%d ", resultado);
    }

    return 0;
}