#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    printf("\nVerificar a posição do menor valor em uma matriz\n\n");
}

int lerTamanho() {
    int tamanho;
    printf("Qual o tamanho da matriz?: ");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerM(int **m, int tamanho) { 
    for(int i = 0; i < tamanho; i++) { 
        for(int j = 0; j < tamanho; j++) { 
            printf("m[%d][%d]: ", i + 1, j + 1); 
            scanf("%d", &m[i][j]); 
        } 
    }
}

void printM(int **m, int tamanho) { 
    for(int i = 0; i < tamanho; i++) { 
        for(int j = 0; j < tamanho; j++) { 
            printf("%d ", m[i][j]); 
        } 
        printf("\n");
    } 
    printf("\n");
}

int posicaoDoMenor(int **m, int tamanho) {
    int menor = m[0][0];
    int posicao = 0;

    for(int i = 0; i < tamanho; i++) {
        for(int j = 0; j < tamanho; j++) {
            if (m[i][j] < menor) {
                menor = m[i][j];
                if (i == j) {
                    posicao = 0;
                } else if (i < j) {
                    posicao = 1;
                } else {
                    posicao = -1;
                }
            }
        }
    }
    return posicao;
}

int main() {
    apresentacao();
    
    int tamanho = lerTamanho();

    int **m1 = (int **)malloc(tamanho * sizeof(int *));
    for (int i = 0; i < tamanho; i++) {
        m1[i] = (int *)malloc(tamanho * sizeof(int));
    }

    lerM(m1, tamanho);  
 
    printf("\nm1\n"); 
    printM(m1, tamanho);  

    int posicao = posicaoDoMenor(m1, tamanho);
    if (posicao == 0) {
        printf("\nO menor valor está na diagonal principal.\n");
    } else if (posicao == 1) {
        printf("\nO menor valor está acima da diagonal principal.\n");
    } else {
        printf("\nO menor valor está abaixo da diagonal principal.\n");
    }

    for (int i = 0; i < tamanho; i++) {
        free(m1[i]);
    }
    free(m1);

    return 0;
}
