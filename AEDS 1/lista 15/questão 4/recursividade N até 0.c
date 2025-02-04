#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nN ate 0 recursivo\n\n");
}
int leiaN(){
    int n;
    printf("\ndigite o valor de n:");
    scanf("%d\n", &n);
    return n;
}
void nAtezero(int n){
    if(n >= 0){
        printf("%d", n);
        nAtezero (n - 1);
    }
}

int main(){
    apresentacao();
    int n = leiaN();
    nAtezero(n);
    return 0;
}