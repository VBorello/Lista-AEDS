#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
const int lin = 3; 
const int col = 2; 
 
void apresentacao(){
    printf("\nManeira mais eficiete \n\n");
}

void lerM(float m[][col]) 
{ 
    for(int i = 0; i < lin; i++){ 
       for(int j = 0; j < col; j++){ 
           printf("m[%d][%d: ", i + 1, j + 1) ; 
           scanf("%f", &m[i][j]); 
       } 
    } 
} 

void printM(float m[][col]) 
{ 
    for(int i = 0; i< lin; i++){ 
       for(int j = 0; j < col; j++){ 
           printf("\nm[%d][%d]= %f", i + 1, j + 1, m[i][j]) ; 
       } 
    } 
} 
 
bool iguais(float a[][col], float b[][col]) 
{ 
    bool iguais = true;  
    int i = 0; 
    for(int i = 0; i < lin; i++) 
    { 
        for(int j = 0; j < col; j++) 
        { 
            if(a[i][j] != b[i][j]) iguais = false; 
        } 
    } 
    return iguais; 
} 
 
int main() { 
 
 apresentacao();
 
 float m1[lin][col]; 
 
 lerM(m1);  
 
 float m2[lin][col]; 
 
 lerM(m2);  
 
 printf("\n\nmatriz 1\n"); 
 
 printM(m1);  
 
 printf("\n\nmatriz 2\n"); 
 
 printM(m2);  
 
 if( iguais(m1, m2) ) printf("\niguais!"); 
 
 else printf("\ndiferentes!");  
 
 return 0;

} 