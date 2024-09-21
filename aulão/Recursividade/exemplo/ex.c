#include <stdio.h>
#include <stdlib.h>


funcao(int n){

    int i;

    if(n == 1){
        i = 1;
    }
    else if(n > 1){
        i = n * funcao(n - 1);
    }

    return i;
}

int main(){

    int numero = 6;
    funcao(numero);

    printf("%d", numero);

    return 0;
}