#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nIdentificador de quantidade de 0 em linhas e colunas de uma matriz\n\n");
}

void lerTamanho(int* tamanho){
    printf("Digite o tamanho da matriz(quadrada): ");
    scanf("%d", tamanho);
}

void lerMatriz(int** m, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("\nDigite o termo[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void lerLin(int* linha){
    printf("\nQual linha da matriz você quer? ");
    scanf("%d", linha);
}

void lerCol(int* coluna){
    printf("\nQual coluna da matriz você quer? ");
    scanf("%d", coluna);
}

bool igualdadeDe0(int** m, int tamanho, int linha, int coluna){
    
    int totalDeZeroLin = 0;
    int totalDeZeroCol = 0;

    for(int i = 0; i < tamanho; i++){

        if(m[i][coluna] == 0){
            totalDeZeroCol++;
        }            
    }

    for(int j = 0; j < tamanho; j++){
        
        if(m[linha][j] == 0){
            totalDeZeroLin++;
        }
    }

    return totalDeZeroCol == totalDeZeroLin;
}

void printMatriz(int **m, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    apresentacao();

    int tamanho;
    lerTamanho(&tamanho);

    int** m = (int**)malloc(tamanho * sizeof(int*));
    for(int i = 0; i < tamanho; i++){
        m[i] = (int*)malloc(tamanho * sizeof(int));
    }

    lerMatriz(m, tamanho);

    int linha, coluna;

    lerLin(&linha);
    lerCol(&coluna);

    linha--;
    coluna--;

    if(igualdadeDe0(m, tamanho, linha, coluna)){
        printf("\nA quantidade de zeros na linha %d é igual à quantidade de zeros na coluna %d:\n\n", linha + 1, coluna + 1);
    } else {
        printf("\nA quantidade de zeros na linha %d é diferente da quantidade de zeros na coluna %d:\n\n", linha + 1, coluna + 1);
    }

    printMatriz(m, tamanho);

    for(int i = 0; i < tamanho; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}
