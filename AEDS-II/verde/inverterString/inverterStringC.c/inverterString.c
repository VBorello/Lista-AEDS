#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invertedor(char* string,int inicio, int tam){

    if(inicio >= tam){
        return;
    }

    char aux = string[inicio];
    string[inicio] = string[tam];
    string[tam] = aux;
    
    invertedor(string, inicio +  1, tam - 1);
}

int main(){
    
    char string[1000];
    scanf(" %[^\n]", string);

    while (!(string[0] == 'F' && string[1] == 'I' && string[2] == 'M' && string[3] == '\0')) {
        int tamanho = strlen(string);
        invertedor(string, 0, tamanho - 1);
        printf("%s\n", string);

        scanf(" %[^\n]", string);
    }

    return 0;
}