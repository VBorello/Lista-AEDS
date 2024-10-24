#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPrimo Sucessor e Antecessor de X\n\n");
}

void lerX(int *x){

    printf("Digite o valor de x: ");
    scanf("%d", x);
}

bool esPrimo(int n){
    int primo = true;
    
    if(n <= 1){
        primo = false;
    }
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            primo = false;
        }
    }

    return primo;
}

void calcularPrimoAntecessorESucessor(int x, int *anterior, int *sucessor){

    int i = x - 1;
    while(*anterior == 0 && i > 1){
        if(esPrimo(i)){
            *anterior = i;
        }
        i--;
    }

    i = x + 1;
    while(*sucessor == 0){
        if(esPrimo(i)){
            *sucessor = i;
        }
        i++;
    }
    

    printf("\nO maior numero primo antes de %d é: %d.\nE o menor numero primo depois de %d é: %d", x, *anterior, x, *sucessor);
}

int main(){
    apresentacao();

    int x;

    lerX(&x);
    
    int anterior = 0;
    int sucessor = 0;

    calcularPrimoAntecessorESucessor(x, &anterior, &sucessor);


    return 0;

}