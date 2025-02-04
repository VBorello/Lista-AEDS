#include <stdio.h>
#include <stdlib.h>

void apresentacao() {
    
    system("clear"); 
    printf("\nCalculador da média dos números vizinhos (incluindo a própria posição) de uma matriz\n\n");
}

void lerTam(int *tam){

    printf("\nDigite o tamanho da matriz: ");
    scanf("%d", tam);
}

int lerLin(){

    int lin;
    printf("Digite a linha: ");
    scanf("%d", &lin);
    return lin - 1;
}

int lerCol(){
    
    int col;
    printf("Digite a coluna: ");
    scanf("%d", &col);
    return col - 1;
}

void lerMatriz(int tam, int m[tam][tam]){

    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("Digite o valor [%d][%d] da matriz: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

float calcularMedia(int tam, int m[tam][tam], int lin, int col){

    if(lin < 0 || lin >= tam || col < 0 || col >= tam){
        return 0;
    }

    int soma = 0;
    int total = 0;

    for(int i = lin - 1; i <= lin + 1; i++){
        for(int j = col - 1; j <= col + 1; j++) {
            if(i >= 0 && i < tam && j >= 0 && j < tam) {  
                soma += m[i][j];
                total++;
            }
        }
    }

    return (float)soma / total;  
}

void printM(int tam, int m[tam][tam]){
    
    printf("\nMatriz:\n");
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int m[tamanho][tamanho]; 
    lerMatriz(tamanho, m);

    int lin = lerLin();
    int col = lerCol();

    if (lin < 0 || lin >= tamanho || col < 0 || col >= tamanho) {
        printf("\nPosição inválida!\n");
        return 1;
    }

    printM(tamanho, m);

    float media = calcularMedia(tamanho, m, lin, col);
    printf("\nA média dos valores vizinhos a %d na posição [%d][%d] é: %.2f\n", m[lin][col], lin + 1, col + 1, media);

    return 0;
}
