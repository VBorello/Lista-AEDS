#include<stdio.h>
#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nSoma de Doid numeros funcao\n\n");
}

void lerNumeros(int* n, int* n2){
    printf("Digite os dois numeros: ");
    scanf("%d %d", n, n2);
}

void somar(int n, int n2){
    int soma = n + n2;
    printf("A soma dos numeros %d e %d é iagual a: %d", n, n2, soma);
}

int main(){
    apresentacao();
    int n, n2;
    lerNumeros(&n, &n2);
    somar(n, n2);

    return 0;
}

