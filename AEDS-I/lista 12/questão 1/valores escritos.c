#include <stdio.h>

void apresentacao(){
    printf("\ntroca a por b\n\n");
}
void troca(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main() {
    apresentacao();

    int a = 5, b = 2;

    printf("qual valor de a:");
    scanf("%d", &a);
    printf("qual valor de b:");
    scanf("%d", &b);
    
    troca(&a, &b);
    
    printf("\n%d, %d", a, b);
    
    return 0;
}