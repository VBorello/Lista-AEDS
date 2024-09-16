#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nFatorial Recursivo\n\n");
}

void lerN(int* n){
    printf("Digite o numero: ");
    scanf("%d", n);
}

int calcularFatorial(int n){

    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n  * calcularFatorial(n - 1);
    }
}

int main(){
    apresentacao();
    
    int n;
    lerN(&n);
    
    if (n < 0) {
        printf("Fatorial não é definido para números negativos.\n");
    } else {
        int fatorial = calcularFatorial(n);
        printf("O fatorial de %d é: %d\n", n, fatorial);
    }

    return 0;
}