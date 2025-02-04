#include <stdio.h>
#include <stdlib.h>

#define tamanhoMAX 100

void apresentacao() {
    printf("\nMaior valor da diagonal principal de uma matriz Recursiva\n\n");
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

int maiorDaDiagonal(int **m, int tamanho, int indice) {
    
    if (indice == tamanho) {
        return m[0][0]; 
    }

    if (indice == tamanho - 1) {
        return m[indice][indice];
    }

    int maiorRestante = maiorDaDiagonal(m, tamanho, indice + 1);
    if (m[indice][indice] > maiorRestante) {
        return m[indice][indice];
    } else {
        return maiorRestante;
    }
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

    int maior = maiorDaDiagonal(m1, tamanho, 0);
    printf("\nO maior valor da diagonal principal é: %d\n", maior);

    for (int i = 0; i < tamanho; i++) {
        free(m1[i]);
    }
    free(m1);

    return 0;
}
