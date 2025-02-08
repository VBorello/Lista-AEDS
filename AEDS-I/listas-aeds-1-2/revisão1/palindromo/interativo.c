#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPalindromo ou não\n\n");
}

void lerString(char *string){
    printf("\nDigite uma string: ");
    scanf("%s", string);

    int i = 0;
    while(string[i] != '\0'){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
        i++;
    }
}

int pegarTam(char *string){

    int tam = 0;
    while(string[tam] != '\0'){
        tam++;
    }
    return tam;
}

bool Palindromo(int tam, char *string){

    bool sucesso = true;

    for(int i = 0; i < tam / 2; i++){
        if(string[i] != string[tam - i - 1]){
            sucesso = false;
        }
    }

    return sucesso;
}

int main() {
    
    char string[100];

    lerString(string);

    int tam = pegarTam(string);

    if(Palindromo(tam, string)){
        printf("\nÉ Palindromo\n");
    }
    else{
        printf("\nNão é Palindromo");
    }

    return 0;
}