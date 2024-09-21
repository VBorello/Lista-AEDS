#include <stdio.h>
#include <stdlib.h>

void leiaNum(int* n){
    printf("\nDigite o valor de n: ");
    scanf("%d", n);
}

void procedimento(int n){
    
    if(n >= 1){
        printf("%d ", n);
        procedimento(n - 1);
    }
    
}

int main(){
    int n;
    leiaNum(&n);

    procedimento(n);

    return 0;
}