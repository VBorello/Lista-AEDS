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

int calcularSomaDaSequencia(int superior, int inferior){

    if(superior > inferior){        
        printf("%d ", superior);
        calcularSomaDaSequencia(superior - 1, inferior);
    }

    if(superior == inferior){
        return superior;
    }
    
    return superior + calcularSomaDaSequencia(superior -1, inferior);

    
}

int main(){
    apresentacao();

    int sup, inf;
    lerLimites(&sup, &inf);

    int soma = calcularSomaDaSequencia(sup, inf);

    printf("\nA soma dos valores entre os limites superior e inferior e: %d", soma);

    return 0;
}
