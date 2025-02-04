#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
 
const int lin = 2; 
const int col = 2; 
 
void apresentacao(){
    printf("\nManeira mais eficiete \n\n");
}

void lerM(int m[][col]) 
{ 
    for(int i = 0; i < lin; i++){ 
       for(int j = 0; j < col; j++){ 
           printf("m[%d][%d]: ", i + 1, j + 1) ; 
           scanf("%d", &m[i][j]); 
       } 
    }
    printf("\n m2:\n");
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
 
 if( iguais(m1, m2) ) printf("\niguais!"); 
 
 else printf("\ndiferentes!");  
 
 return 0;

} 