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

void printMatriz(int tam, int m[tam][tam]){

    printf("\n");
    for(int i = 1; i < tam; i++){
        for(int j = 1; j < tam; j++){
            printf(" %d", m[i][j]);
        }
        printf("\n");
    }
}

int somaDiagonalPrimaria(int tam, int m[tam][tam]){

    int soma = 0;
    for(int i = 1; i < tam; i++){
        soma += m[i][i];
    }   
    return soma;
}

int somaDiagonalSecundaria(int tam, int m[tam][tam]){

    int soma = 0;
    for(int i = 1; i < tam; i++){
        soma += m[i][tam - i];
    }   
    return soma;
}

void printDiagonalPrincipal(int tam, int m[tam][tam]) {
    printf("\nDiagonal Principal:\n");
    for (int i = 1; i < tam; i++) {
        printf("%d ", m[i][i]);  
        printf("\n");
    }
    
}

void printDiagonalSecundaria(int tam, int m[tam][tam]){

    printf("\nDiagonal Secundaria:\n");
    for(int i = 1; i < tam; i++){
        printf("%d ", m[i][tam - i]);   
        printf("\n");
    }
}

int main(){
    apresentacao();

    int tamanho = lerTam();

    int matriz[tamanho][tamanho];
    lerMatriz(tamanho, matriz);

    printMatriz(tamanho, matriz);
    printDiagonalPrincipal(tamanho, matriz);
    printDiagonalSecundaria(tamanho, matriz);

    int soma = somaDiagonalPrimaria(tamanho, matriz);
    printf("\nA soma dos valores da diagonal Principal da matriz e: %d", soma);
    int soma2 = somaDiagonalSecundaria(tamanho, matriz);
    printf("\nA soma dos valores da diagonal Secundária da matriz e: %d", soma2);

    return 0;
}