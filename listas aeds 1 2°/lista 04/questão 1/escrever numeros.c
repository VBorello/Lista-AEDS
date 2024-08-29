#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\ninteiros de 1 a 10 teste no final\n\n");
}

void print10(){

    int i = 10;
    do{
        printf("%d ", i);
        i--;
    }while(i >= 0);
    
}

int main(){

    apresentacao();

    print10();

    return 0;
}