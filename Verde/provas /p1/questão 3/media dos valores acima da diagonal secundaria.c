#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nMedia dos valores acima da diagonal secundária\n\n");
}

void lerTam(int* tam){
    printf("Digite o tamanho da matriz(quadrada): ");
    scanf("%d", tam);
}

void lerMatriz(int** m, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("\nDigite o valor de [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

float calcularMediaDiagonalsec(int** m, int tam){
   
    int total = 0;
    int diagonal = 0;

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(i + j < tam - 1){
                    total += m[i][j];
                    diagonal++;
            }
        }
    }

    float media = (float)total / diagonal;

    return media;
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
    lerTam(&tamanho);

    int** m = (int**)malloc(tamanho * sizeof(int*));
    for(int i = 0; i < tamanho; i++){
        m[i] = (int*)malloc(tamanho * sizeof(int));
    }

    lerMatriz(m, tamanho);
    float media = calcularMediaDiagonalsec(m, tamanho); 
    printf("\nA média dos valores acima da diagonal secundária é: %.2f\n\n", media);

    printMatriz(m, tamanho);

    for(int i = 0; i < tamanho; i++){
        free(m[i]);
    }
    free(m);

    return 0;
}