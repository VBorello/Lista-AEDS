#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool palindromoRec(char* string, int indice, int tam){

    if (indice >= tam) {
        return true;
    }

    
    if(string[indice] != string[tam]){
        return false;
    }

    return palindromoRec(string, indice + 1, tam - 1);

}

int main(){

    char string[1000];
    scanf(" %[^\n\r]", string);

    int tam = strlen(string) - 1;

    while(strcmp(string, "FIM")){
        if(palindromoRec(string, 0, tam)){
            printf("SIM\n");       
        }
        else{
            printf("NÃO\n");
        }

        scanf(" %[^\n\r]", string);
    }

    
    
    getchar();

    return 0;
}
