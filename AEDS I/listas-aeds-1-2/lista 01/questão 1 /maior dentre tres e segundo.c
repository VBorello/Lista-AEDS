#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nMaior dentre três números\n\n");
}

void lerTermos(int* n1, int* n2, int* n3){
    printf("Digite os três números separados por espaços: ");
    scanf("%d %d %d", n1, n2, n3);
}

int identificarMaior(int n1, int n2, int n3){
    int maior = n1;

    if(n2 > maior){
        maior = n2;
    }
    if(n3 > maior){
        maior = n3;
    }

    return maior;
}

int identificarSegundoMaior(int n1, int n2, int n3){
    int maior = identificarMaior(n1, n2, n3);
    int segundoMaior;

    if (n1 != maior && (n1 > n2 || n2 == maior) && (n1 > n3 || n3 == maior)) {
        segundoMaior = n1;
    } else if (n2 != maior && (n2 > n1 || n1 == maior) && (n2 > n3 || n3 == maior)) {
        segundoMaior = n2;
    } else {
        segundoMaior = n3;
    }

    return segundoMaior;
}

int main(){
    apresentacao();

    int n1, n2, n3;
    lerTermos(&n1, &n2, &n3);

    int maior = identificarMaior(n1, n2, n3);
    int segundoMaior = identificarSegundoMaior(n1, n2, n3);

    printf("\nO maior número é: %d", maior);
    printf("\nO segundo maior número é: %d\n", segundoMaior);

    return 0;
}
