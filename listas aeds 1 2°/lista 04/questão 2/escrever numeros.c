#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\ninteiros de 10 a 1 teste no inicio\n\n");
}

void escrever(){

    int i = 10;
    while(i >= 0){
        printf("%d ", i);
        i--;
    }
}

int main(){

    apresentacao();
    escrever();

    return 0;
}