#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\n Soma total Da Matriz\n");
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

int somaMatriz(int tam, int m[tam][tam]){

    int soma = 0;
    for(int i = 1; i < tam; i++){
        for(int j = 1; j < tam; j++){
            soma += m[i][j];
        }   
        printf("\n");
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

    int total = somaMatriz(tamanho, matriz);

    printMatriz(tamanho, matriz);

    printf("\nA soma dos valores da matriz e: %d", total);

    return 0;
}