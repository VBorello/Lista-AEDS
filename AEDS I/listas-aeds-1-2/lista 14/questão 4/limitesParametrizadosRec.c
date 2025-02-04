#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nLimites Parametrizados Recursivo\n");
}

void lerLimites(int* superior, int* inferior){
    
    bool erro;
    
    do{
        printf("\nDigite os limites superior: ");
        scanf("%d %d", superior, inferior);
        erro = (*inferior > *superior);
        if(erro){
            printf("\nO limite superior não pode ser menor que o inferior");
        }
    }while(erro);
}

void calcularSequencia(int superior, int inferior){
    
    printf("%d ", superior);

    if(superior > inferior){
        calcularSequencia(superior - 1, inferior);
        printf("%d ", superior);
    }
}

int main(){
    apresentacao();

    int sup, inf;
    lerLimites(&sup, &inf);

    calcularSequencia(sup, inf);

    return 0;
}
