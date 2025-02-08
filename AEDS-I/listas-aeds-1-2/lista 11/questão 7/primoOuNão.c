#include <stdio.h>
#include <stdlib.h>

void apresentaco(){
    printf("\nPrimo das funcoes\n\n");
}

int lerN(){
    int n;
    printf("Digite o numero: ");
    scanf("%d", &n);
    return n;
}

int primoOuNao(int n){
    
    if(n < 2){
        return 0;
    }
    
    for(int i = 2; i <= n / 2; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    apresentaco();

    int numero = lerN(); 

    if (primoOuNao(numero)) {
        printf("\n%d e primo.\n", numero);
    } else {
        printf("\n%d nao e primo.\n", numero);
    }

    return 0;
}