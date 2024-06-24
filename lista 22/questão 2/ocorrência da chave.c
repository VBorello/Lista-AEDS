#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int lin = 2;
const int col = 2;

void apresentacao(){
    printf("\nContador de Chave \n\n");
}

void lerM(int m[][col]) 
{ 
    for(int i = 0; i < lin; i++){ 
       for(int j = 0; j < col; j++){ 
           printf("m[%d][%d]: ", i + 1, j + 1) ; 
           scanf("%d", &m[i][j]); 
       } 
    }
}

void printM(int m[][col]) 
{ 
    for(int i = 0; i< lin; i++){ 
       for(int j = 0; j < col; j++){ 
           printf("\nm[%d][%d]= %d", i + 1, j + 1, m[i][j]) ; 
       } 
    } 
} 

bool iguais(int a[][col], int b[][col]) 
{ 
    bool iguais = true;  

    for(int i = 0; i < lin; i++){ 
        for(int j = 0; j < col; j++){ 
            if(a[i][j] != b[i][j]) iguais = false; 
        } 
    } 
    return iguais; 
} 

void qtdChave(int m[][col], int chave){
    int qtd = 0;
    for (int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(m[i][j] == chave){
                qtd++;
            }
        }
    }
    printf("\nA chave %d aparece %d vez(es) na matriz.", chave, qtd);
}
 
int main() { 
 apresentacao();
 
 int m1[lin][col]; 
 lerM(m1);  
 
 int m2[lin][col]; 
 lerM(m2);  
 
 printf("\n\nmatriz 1\n"); 
 printM(m1);  
 
 printf("\n\nmatriz 2\n"); 
 printM(m2);  
 
 if( iguais(m1, m2) ) 
    printf("\n\nMatrizes iguais!"); 
 else 
    printf("\n\nMatrizes diferentes!");  

 int chave;
 printf("\n\nDigite a chave para contar na matriz 1: ");
 scanf("%d", &chave);
 qtdChave(m1, chave);
 
 return 0;
}
