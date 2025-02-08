#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\n Soma Linha Da Matriz\n");
}

int lerTam(){
    int tam;
    printf("\nDigite o tamanho da matriz(Quadrada): ");
    scanf("%d", &tam);

    tam += 1;

    return tam;
}

void lerMatriz(int tam, int m[tam][tam]){

    for(int i = 1; i < tam; i++){
        for(int j = 1; j < tam; j++){
            printf("\nDigite o valor[%d][%d] da matriz: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void lerLin(int *lin){
    printf("\nDigite a linha da matriz que quer somar seus valores: ");
    scanf("%d", lin);
}

int somaMatriz(int tam, int lin, int m[tam][tam]){

    int soma = 0;
    for(int j = 1; j < tam; j++){
            soma += m[lin][j];
    }

    return soma;
}

void printMatriz(int tam, int m[tam][tam]){

    printf("\n");
    for(int i = 1; i < tam; i++){
        for(int j = 1; j < tam; j++){
            printf("%d ", m[i][j]);
        }   
        printf("\n");
    }
}

int main(){
    apresentacao();

    int tamanho = lerTam();

    int matriz[tamanho][tamanho];
    lerMatriz(tamanho, matriz);

    int linha;
    lerLin(&linha);

    int total = somaMatriz(tamanho, linha, matriz);

    printMatriz(tamanho, matriz);

    printf("\nA soma dos valores da linha %d da matriz e: %d", linha, total);

    return 0;
}