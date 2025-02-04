#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COL 3

void apresentacao(){
    printf("\nLin = Col?\n\n");
}

int lerX(){

    int x;
    printf("\nDigite x que será o valor correspondente a linha e coluna a ser comparada: ");
    scanf("%d", &x);

    return x - 1;
}

void lerMatriz(int m[][COL]){

    for(int i = 0; i < COL; i++){
        for(int j = 0; j < COL; j++){
            printf("\nDigite o valor [%d][%d]:", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        } 
    }
}

bool comparaLinCol(int m[][COL], int x){

    bool iguais = true;
    for(int i = 0; i < COL; i++){
        for(int j = 0; j < COL; j++){
            if(m[x][j] != m[i][x]){
                iguais = false;
            }
        } 
    }

    return iguais;
}

void printM(int m[][COL]){

    for(int i = 0; i < COL; i++){
        for(int j = 0; j < COL; j++){
            printf("%d ", m[i][j]);
        } 
        printf("\n");
    }
}

int main(){
    apresentacao();

    int m[COL][COL];
    lerMatriz(m);
    
    int x = lerX();

    if(comparaLinCol(m, x)){
        printf("\nA linha %d é igual a coluna %d", x + 1, x + 1);
    }
    else{
        printf("\nA linha %d é diferente da coluna %d", x + 1, x + 1);
    }

    printf("\n");
    printM(m);

    return 0;
}