#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nInteiros de 10 a 1 for\n\n");
}

void escrever(){

    for(int i = 10; i >= 0; i--){
        printf("%d ", i);
    }
}


int main(){

    apresentacao();
    escrever();

    return 0;
}