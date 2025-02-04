#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void apresentacao(){
    printf("\nMaiusculo para minusculo\n\n");
}

void lerString(char *string){
    
    printf("\nDigite a string: ");
    scanf("%s", string);

    int i = 0;
    while (string[i] != '\0'){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
        i++;
    }    
}

int pegarTam(char *string){
    
    int tam = 0;
    while (string[tam] != '\0'){
        tam++;
    }
    
    return tam;
}

void converterParaMaiusculo(int tam, char *string){
    
    if(tam <= 0){
        return;
    }

    if(islower(*string)){
        *string = toupper(*string);
    }

    converterParaMaiusculo(tam - 1, string + 1);
}

int main(){
    apresentacao();

    char string[100];

    lerString(string);
    int tam = pegarTam(string);
    
    printf("\nString Minuascula: %s\n", string);

    converterParaMaiusculo(tam, string);

    printf("\nString Maiuscula: %s\n", string);
    
    return 0;
}