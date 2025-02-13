#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool palindromo(char* string){
    
    bool palindromo = true;
    int tam = strlen(string);

    for(int i = 0; i < tam / 2; i++){
        if(string[i] != string[tam - i - 1]){
            palindromo = false;
            i = tam;
        }
    }

    return palindromo;
}

int main(){
    
    char string[100];

    scanf(" %[^\n\r]", string);
    while (strcmp(string, "FIM")){
        if(palindromo(string)){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

        scanf(" %[^\n\r]", string);
    }

    getchar();
    
    return 0;
}