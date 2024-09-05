#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nMaior entre dois valores\n\n");
}

void lerNumeros(int* n1, int*n2){
    printf("Digite os dois valores de maneira espaçada: ");
    scanf("%d %d", n1, n2);
}

void identificadorDoMaior(int n1, int n2){
    int maior = n1;
    if(n2 > n1){
        maior = n2;
        printf("\n%d e maior que %d", maior, n1);
    }
    else{
        printf("\n%d e maior que %d", maior, n2);
    }
}

int main(){
    apresentacao();

    int n1, n2;
    lerNumeros(&n1, &n2);

    identificadorDoMaior(n1, n2);

    return 0;
}