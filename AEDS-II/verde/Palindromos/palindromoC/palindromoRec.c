#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool palindromoRec(char* string, int index, bool palindromo) {
    
    int tam = strlen(string);

    if (index < tam / 2) {
        if(string[index] != string[tam - 1 - index]){
     
            palindromo = false;
        }   
    }
    else if (index >= tam) {
        return palindromo;
    }

    return palindromoRec(string, index + 1, palindromo);
}

int main() {

    char string[1000];
    scanf(" %[^\n\r]", string);

    bool palindromo = true;
    
    while (strcmp(string, "FIM")) {
        
        if (palindromoRec(string, 0, palindromo)) {
            printf("SIM\n");       
        } else {
            printf("NÃO\n");
        }
        
        scanf(" %[^\n\r]", string);
    }
    
    return 0;
}
