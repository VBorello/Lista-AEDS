#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* combinar(const char* string1, const char* string2){
    
    static char combinada[1000];
    int iStr1 = 0;
    int iStr2 = 0;
    int iCombinada = 0;

    while(string1[iStr1] != '\0' && string2[iStr2] != '\0'){
        combinada[iCombinada++] = string1[iStr1++];
        combinada[iCombinada++] = string2[iStr2++];
    }

    while(string1[iStr1] != '\0'){
        combinada[iCombinada++] = string1[iStr1++];
    }

    while(string2[iStr2] != '\0'){
        combinada[iCombinada++] = string2[iStr2++];
    }
    
    combinada[iCombinada] = '\0';

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