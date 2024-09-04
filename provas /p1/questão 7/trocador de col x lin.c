#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nTrocador de Linha por Colunas\n\n");
}

void lerTamanho(int* tam){
    printf("Digite o tamanho da matriz: ");
    scanf("%d", tam);
}

void lerMatriz(int** m, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("\nDigite o valor[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

int lerLin(int* lin){
    printf("\nDigite a Linha que tu queres:");
    scanf("%d", lin);
}

int lerCol(int* col){
    printf("\nDigite a Linha que tu queres:");
    scanf("%d", col);
}

void trocador(int** m, int tam, int aux){
    for(int i = 0)

}

int main(){
    apresentacao();

    return 0;
}