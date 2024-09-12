#include <stdio.h>
#include <stdlib.h>

void apresentacao(int i){
    printf("%d ", i);
    
    if(i < 10){
        apresentacao(i + 1);
        printf("%d ", i);
    }
}

void teste(){
    printf("Recursividade");
}

int main(){
    apresentacao(1);

    return 0;
}