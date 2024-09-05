//Verificar se dois números naturais são primos entre si. Dois números naturais são ditos primos entre si
//caso não exista divisores comuns a ambos, exceto o número 1.
//O conjunto dos números naturais é composto pelos valores inteiros e positivos.
//Rejeitar a leitura de números inválidos (não pertencentes ao conjunto de números naturais).
//Ao final, permitir ao usuário verificar outros números ou encerrar. Rejeitar a leitura de valores inválidos
//– apenas ‘S’ para “sim” ou‘N’ para “não”.

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPrimos entre sí\n\n");
}

int lerNumeros(int* n1, int* n2){
    printf("Digite dois numeros: ");   
    scanf("%d %d", n1, n2);
}

int mdc(int n1, int n2){
    while (n2 != 0)
    {
        int aux = n2;
        n2 = n1 % n2;
        n1 = aux;
    }

    return n1;
}

int primosOuNao(int n1, int n2){
    return mdc(&n1, &n2) == 1;
}

