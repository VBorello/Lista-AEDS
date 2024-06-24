#include <stdio.h>
#include <stdlib.h>

int lerTamanho() {
    int tamanho;
    printf("Qual o tamanho da matriz?: ");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerM(int **m, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            printf("m[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void printM(int **m, int tamanho) { 
    for (int i = 0; i < tamanho; i++) { 
        for (int j = 0; j < tamanho; j++) { 
            printf("%d ", m[i][j]); 
        } 
        printf("\n");
    } 
    printf("\n");
}

int primeiraOcorrenciaRecAux(double **m, int linhas, int colunas, int i, int j, double maiorValor, int linhaMaior) {
    if (i >= linhas) {
        return linhaMaior;
    }
    if (j >= colunas) {
        return primeiraOcorrenciaRecAux(m, linhas, colunas, i + 1, 0, maiorValor, linhaMaior);
    }
    if (m[i][j] > maiorValor) {
        maiorValor = m[i][j];
        linhaMaior = i;
    }
    return primeiraOcorrenciaRecAux(m, linhas, colunas, i, j + 1, maiorValor, linhaMaior);
}

int primeiraOcorrenciaRec(double **m, int tamanho) {
    return primeiraOcorrenciaRecAux(m, tamanho, tamanho, 0, 0, m[0][0], 0);
}

int main() {
    int tamanho = lerTamanho();

    double **m = (double **)malloc(tamanho * sizeof(double *));
    for (int i = 0; i < tamanho; i++) {
        m[i] = (double *)malloc(tamanho * sizeof(double));
    }

    lerM(m, tamanho);

    printM(m, tamanho);

    int linhaMaior = primeiraOcorrenciaRec(m, tamanho);
    printf("A primeira ocorrência do maior valor está na linha %d\n", linhaMaior + 1);

    for (int i = 0; i < tamanho; i++) {
        free(m[i]);
    }
    free(m);

    return 0;
}
