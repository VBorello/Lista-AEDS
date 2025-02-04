#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("\nFibonacci\n\n");

    int a = 1;
    int b = 1;
    int prox;

    int termos;
    printf("quantos termos do fibonacci queres ver: ");
    scanf("%d", &termos);

    printf("%d %d ", a, b);
    for(int i = 3; i < termos; i++){
        prox = a + b;
        a = b;
        b = prox;
        printf("%d ", prox);
    }

    return 0;
}