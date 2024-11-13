#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nMaiores valores nas colunas da Matriz para um vetor\n\n");
}

void lerTam(int *tam){
    printf("\nDigite o tamanho da matriz(quadrada): ");
    scanf("%d", tam);
}

void lerMatriz(int tam, int m[tam][tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("\nDigite o valor [%d][%d] da matriz: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void pegarMaiores(int tam, int m[tam][tam]){
    
    int *maiores = (int *)malloc(tam * sizeof(int));
    
    for(int i = 0; i < tam; i++){
        maiores[i] = 0;
    }

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(m[i][j] > maiores[j]){
                maiores[j] = m[i][j];
            }
        }
    }

    printf("\nMatriz:\n");
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nMaiores:\n");
    for(int i = 0; i < tam; i++){
        printf("%d ", maiores[i]);
    }
    
}


int main(){
    apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int matriz[tamanho][tamanho];

    lerMatriz(tamanho, matriz);
    pegarMaiores(tamanho, matriz);

    return 0;
}