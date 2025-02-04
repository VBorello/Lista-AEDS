#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nArmazena Limites acima/abaixo das diagonais em vetores\n\n");
}


void lerTam(int *tam){

    printf("\nDigite o tamanho da matriz: ");
    scanf("%d", tam);
}

void lerMatriz(int tam, int m[tam][tam]){
    
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            printf("\nDigite o valor [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void armazenarAcimaDiagonal(int tam, int m[tam][tam], int **vetor, int *tamanhoVetor) {
    
    *tamanhoVetor = (tam * (tam - 1)) / 2;
    *vetor = (int *)malloc(*tamanhoVetor * sizeof(int));

    int indice = 0;
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            (*vetor)[indice] = m[i][j];
            indice++;
        }
    }
}

void armazenarAbaixoDiagonal(int tam, int m[tam][tam], int **vetor, int *tamanhoVetor){

    *tamanhoVetor = (tam * (tam - 1)) / 2;
    *vetor = (int *)malloc(*tamanhoVetor * sizeof(int));

    int indice = 0;
    for (int i = 1; i < tam; i++) {
        for (int j = 0; j < i; j++) {
            (*vetor)[indice] = m[i][j];
            indice++;
        }
    }
}

void armazenarAcimaDiagonalSecundaria(int tam, int matriz[tam][tam], int **vetor, int *tamanhoVetor) {
    
    *tamanhoVetor = (tam * (tam - 1)) / 2;
    *vetor = (int *)malloc(*tamanhoVetor * sizeof(int));

    int indice = 0;
    for(int i = 0; i < tam - 1; i++){
        for (int j = 0; j < tam - 1 - i; j++){ 
            (*vetor)[indice] = matriz[i][j];
            indice++;
        }
    }
}

void armazenarAbaixoDiagonalSecundaria(int tam, int matriz[tam][tam], int **vetor, int *tamanhoVetor) {
    
    *tamanhoVetor = (tam * (tam - 1)) / 2;
    *vetor = (int *)malloc(*tamanhoVetor * sizeof(int));

    int indice = 0;
    for (int i = 1; i < tam; i++) {
        for (int j = tam - i; j < tam; j++) {
            (*vetor)[indice] = matriz[i][j];
            indice++;
        }
    }
}

void printV(int tam, int v[tam]){

    for(int i = 0; i < tam; i++) {     
        printf("%d ", v[i]);
    }
}

void printMatriz(int tam, int m[tam][tam]){
    
    printf("\nMatriz:\n");
    for (int i = 0; i < tam; i++) {
        for (int j =0; j < tam; j++) { 
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int m[tamanho][tamanho];
    lerMatriz(tamanho, m);

    printMatriz(tamanho, m);

    int *acimaDiagonal;
    int tamanhoAcimaDiagonal;
    armazenarAcimaDiagonal(tamanho, m, &acimaDiagonal, &tamanhoAcimaDiagonal);
    printf("\nValores acima da diagonal principal:\n");
    printV(tamanhoAcimaDiagonal, acimaDiagonal);

    int *abaixoDiagonal;
    int tamanhoAbaixoDiagonal;
    armazenarAbaixoDiagonal(tamanho, m, &abaixoDiagonal, &tamanhoAbaixoDiagonal);
    printf("\nValores abaixo da diagonal principal:\n");
    printV(tamanhoAbaixoDiagonal, abaixoDiagonal);

    int *acimaDiagonalSecundaria;
    int tamanhoAcimaDiagonalSecundaria;
    armazenarAcimaDiagonalSecundaria(tamanho, m, &acimaDiagonalSecundaria, &tamanhoAcimaDiagonalSecundaria);
    printf("\nValores acima da diagonal secundária:\n");
    printV(tamanhoAcimaDiagonalSecundaria, acimaDiagonalSecundaria);

    int *abaixoDiagonalSecundaria;
    int tamanhoAbaixoDiagonalSecundaria;
    armazenarAbaixoDiagonalSecundaria(tamanho, m, &abaixoDiagonalSecundaria, &tamanhoAbaixoDiagonalSecundaria);
    printf("\nValores abaixo da diagonal secundária:\n");
    printV(tamanhoAbaixoDiagonalSecundaria, abaixoDiagonalSecundaria);

    free(acimaDiagonal);
    free(abaixoDiagonal);
    free(acimaDiagonalSecundaria);
    free(abaixoDiagonalSecundaria);
    
    return 0;
}