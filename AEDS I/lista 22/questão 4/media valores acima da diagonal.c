#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int lin = 3;
const int col = 3;

void apresentacao() {
    printf("\nMedia dos Valores Acima da Diagonal da mQuadrada \n\n");
}

void lerM(int m[][col]) { 
    for(int i = 0; i < lin; i++) { 
       for(int j = 0; j < col; j++) { 
           printf("m[%d][%d]: ", i + 1, j + 1); 
           scanf("%d", &m[i][j]); 
       } 
    }
}

void printM(int m[][col]) { 
    for(int i = 0; i < lin; i++) { 
       for(int j = 0; j < col; j++) { 
           printf("\nm[%d][%d]= %d", i + 1, j + 1, m[i][j]); 
       } 
    } 
} 

bool iguais(int a[][col], int b[][col]) { 
    for(int i = 0; i < lin; i++) { 
        for(int j = 0; j < col; j++) { 
            if(a[i][j] != b[i][j]) 
                return false; 
        } 
    } 
    return true; 
} 

void qtdChave(int m[][col], int chave) {
    int qtd = 0;
    for (int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            if(m[i][j] == chave) {
                qtd++;
            }
        }
    }
    printf("\nA chave %d aparece %d vez(es) na matriz.", chave, qtd);
}

bool possuiChave(int m[][col], int chave) {
    for(int i = 0; i < lin; i++) {
        for(int j = 0; j < col; j++) {
            if(m[i][j] == chave) {
                return true;
            }
        }
    }
    return false;
}

void mediaAcimaDiagonal(int m[][col]) {
    float soma = 0;
    int n = 0;
    
    for(int i = 0; i < lin; i++) {
        for(int j = i + 1; j < col; j++) {
            soma += m[i][j];
            n++;
        }
    }

    if (n > 0) {
        float media = soma / n;
        printf("\nA media dos valores acima da diagonal e igual a %.2f", media);
    } else {
        printf("\nNao ha valores acima da diagonal principal.");
    }
}
 
int main() { 
    apresentacao();
 
    int m1[lin][col]; 
    lerM(m1);  
 
    int m2[lin][col]; 
    lerM(m2);  
 
    printf("\n\nMatriz 1\n"); 
    printM(m1);  
 
    printf("\n\nMatriz 2\n"); 
    printM(m2);  
 
    if(iguais(m1, m2)) 
        printf("\n\nMatrizes iguais!"); 
    else 
        printf("\n\nMatrizes diferentes!");  

    int chave;
    printf("\n\nDigite a chave para contar na matriz 1: ");
    scanf("%d", &chave);
 
    if (possuiChave(m1, chave))
        printf("\nA chave %d está na matriz", chave);
    else
        printf("\nA chave %d não está na matriz", chave);

    qtdChave(m1, chave);

    mediaAcimaDiagonal(m1);
 
    return 0;
}
