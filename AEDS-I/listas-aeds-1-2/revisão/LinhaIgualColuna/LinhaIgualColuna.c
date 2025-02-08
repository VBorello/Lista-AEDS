#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nCol igual a Lin?\n\n");
}

void pegarTam(int *tam){
    printf("Digite o tamanho da matriz(quadrada):");
    scanf("%d", tam);
}

void lerMatriz(int tam, float m[][tam]){

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("\nDigite o valor [%d][%d] da matriz: ", i + 1, j + 1); 
            scanf("%f", &m[i][j]);
        }
    }
}

void lerLinCol(int *lin, int *col){
    printf("Digite a linha e a coluna que deseja saber se são iguais: ");
    scanf("%d %d", lin, col);
}

bool linColIguais(int tam, float m[][tam], int lin, int col){

    bool iguais = true;

    int x = 0;
    
    while (iguais && x < tam){
        if(m[lin][x] != m[x][col]){
            iguais = false;
        }
        x++;
    }
    
    return iguais;
}

void printM(int tam, float m[][tam]){
    
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%0.f ", m[i][j]); 
        }
        printf("\n");
    }
}

int main(){
    apresentacao();

    int tamanho;
    pegarTam(&tamanho);


    float matriz[tamanho][tamanho];
    lerMatriz(tamanho, matriz);


    int linha, coluna;
    lerLinCol(&linha, &coluna);

    printM(tamanho, matriz);

    if(linColIguais(tamanho, matriz, linha, coluna)){
        printf("\na linha: %d e a coluna: %d são iguais.", linha, coluna);
    }
    else{
        printf("\na linha: %d e a coluna: %d são diferentes.", linha, coluna);
    }

    

    return 0;
}