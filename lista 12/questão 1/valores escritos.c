#include <stdio.h>

void troca(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main() {
    int a = 5, b = 2;
    
    troca(&a, &b);
    
    printf("\n%d, %d", a, b);
    
    return 0;
}