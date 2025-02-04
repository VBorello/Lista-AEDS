#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("\nSequencia 1//100\n\n");

    int numerador = 10;
    int denominador = 100;
    int termos = 10;

    for(int i = 0; i < termos; i++){
        
        if(i > 0){
            numerador++;
            denominador--;
        }
        
        if(i % 2 == 0){
            printf("%d/%d ", numerador, denominador);
        }
        else{
            printf("%d/%d ", denominador, numerador);
        }

    }

    return 0;
}