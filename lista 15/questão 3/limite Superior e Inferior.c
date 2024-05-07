#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nLimite superior e inferior parametrizado\n\n");
}
int leialimite(char *str){
    int lim;
    printf("\n%s", str);
    scanf("%d", &lim);
    return lim;
}
void escreva(int a, int b){
    printf("%d", a);
    if(a < b){
        escreva (a + 1, b);
    }
}

int main(){
    apresentacao();
    int a = leialimite("limite inferior:");
    int b= leialimite("limite superior:");
    escreva(a, b);
    return 0;
}