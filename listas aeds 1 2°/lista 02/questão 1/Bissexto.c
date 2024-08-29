#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nBissexto ou não\n\n");
}

void lerAno(int* ano){
    
    printf("Qual ano:");
    scanf("%d", ano);
}

bool verSeEBissexto(int ano){
    
    if ((ano % 4 == 0 && ano % 100 != 0) || ( ano % 400 == 0)) {
        printf("\no ano e bissexto");
        return true;
    }
    printf("\no ano não e bissexto");
    return false;
}

int main(){
    
    apresentacao();
    int ano;
    lerAno(&ano);

    verSeEBissexto(ano);

    return 0;
}