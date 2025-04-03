#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* combinar(const char* string1, const char* string2){
    
    static char combinada[1000];
    int tamString1 = 0;
    int tamString2 = 0;
    int tamCombinada = 0;

    while(string1[tamString1] != '\0' && string2[tamString2] != '\0'){
        combinada[tamCombinada++] = string1[tamString1++];
        combinada[tamCombinada++] = string2[tamString2++];
    }

    while(string1[tamString1] != '\0'){
        combinada[tamCombinada++] = string1[tamString1++];
    }

    while(string2[tamString2] != '\0'){
        combinada[tamCombinada++] = string2[tamString2++];
    }
    
    combinada[tamCombinada] = '\0';

    return combinada;
}

int main(){

    char string1[1000];
    char string2[1000];

    while(scanf("%s %s", string1, string2) == 2){
        printf("%s\n", combinar(string1, string2));
    }
        
    return 0;
}