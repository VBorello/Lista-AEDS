#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPar ou impar funcao\n\n");
}

int lerNum(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    return n;
}

bool parOuImpar(int n){
    bool par;

    if(n % 2 == 0){
        printf("\nO numero %d e par", n);
        par = true;
        return par;
    }
    else if(n % 2 != 0){
        printf("\nO numero %d e imapar", n);
        par = false;
        return par;
    }
}

int main(){
    apresentacao();
    int n = lerNum();

    parOuImpar(n);

    return 0;
}