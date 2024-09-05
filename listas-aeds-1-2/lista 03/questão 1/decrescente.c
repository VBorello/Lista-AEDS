#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\ntres Valores em ordem decrescente\n\n");
}

void lerValores(int* n1, int* n2, int* n3){
    
    printf("Digite tres numeros de maneira espaçada:");
    scanf("%d %d %d", n1, n2, n3);
}


void decrescente(int n1, int n2, int n3){

    if(n1 >= n2 && n1 >= n3){
        if(n2 >= n3){
            printf("\n %d %d %d\n", n1, n2, n3);
        } else {
            printf("\n %d %d %d\n", n1, n3, n2);
        }
    } else if(n2 >= n1 && n2 >= n3){
        if(n1 >= n3){
            printf("\n %d %d %d\n", n2, n1, n3);
        } else {
            printf("\n %d %d %d\n", n2, n3, n1);
        }
    } else if(n3 >= n1 && n3 >= n2){
        if(n1 >= n2){
            printf("\n %d %d %d\n", n3, n1, n2);
        } else {
            printf("\n %d %d %d\n", n3, n2, n1);
        }
    }
}


int main(){

    apresentacao();
    int n1, n2, n3;
    lerValores(&n1, &n2, &n3);

    decrescente(n1, n2, n3);
    
    return 0;
}