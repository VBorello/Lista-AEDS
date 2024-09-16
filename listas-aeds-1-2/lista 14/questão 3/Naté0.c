#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nDe n até 0 recursivo\n\n");
}

void lerN(int* n){
    printf("Digite o valor de n: ");
    scanf("%d", n);
}

void nAte0(int n){
    
    if(n >= 0){
        printf("%d ", n);
        nAte0(n - 1);
    }
}

int main(){
    apresentacao();
    int n;
    lerN(&n);

    nAte0(n);

    return 0;
}