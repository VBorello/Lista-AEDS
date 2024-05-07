#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nK-esimo termo de fibonacci\n\n");
}

int fibonacci(int n){
    if(n <= 1){
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

void escreverFibonacci(int n, int numTermos){
    if(n >= numTermos){
        return;
    }
    printf("%d ", fibonacci(n));
    escreverFibonacci(n + 1, numTermos);
}

int main() {
    int num_termos;
    
    printf("Digite o numero de termos da sequencia de Fibonacci: ");
    scanf("%d", &num_termos);
    
    printf("Sequencia de Fibonacci com %d termos:\n", num_termos);
    escreverFibonacci(0, num_termos);
   
    return 0;
}
