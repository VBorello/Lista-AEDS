#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nMaior da Linha matriz\n\n");
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

int primeiraOcorrencia(double **matriz, int tamanho) {
    int linhaMaior = 0;
    double maiorValor = matriz[0][0];

    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (matriz[i][j] > maiorValor) {
                maiorValor = matriz[i][j];
                linhaMaior = i;
            }
        }
    }

    return linhaMaior;
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

int main() {
    int tamanho = lerTamanho();

    double **m1 = (double **)malloc(tamanho * sizeof(double *));
    for (int i = 0; i < tamanho; i++) {
        m1[i] = (double *)malloc(tamanho * sizeof(double));
    }

    lerM(m1, tamanho);

    printM(m1, tamanho);
    
    int linhaMaior = primeiraOcorrencia(m1, tamanho);
    printf("A primeira ocorrência do maior valor está na linha %d\n", linhaMaior + 1);

    for (int i = 0; i < tamanho; i++) {
        free(m1[i]);
    }
    free(m1);

    return 0;
}
