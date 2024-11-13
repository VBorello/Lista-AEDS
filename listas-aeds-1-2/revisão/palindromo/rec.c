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

bool Palindromo(int inicio, int final, char *string){

    if(inicio >= final){
        return true;
    }

    if(string[inicio] != string[final]){
        return false;
    }

    return Palindromo(inicio + 1, final - 1, string);
    
}

int main() {
    
    char string[100];

    lerString(string);

    int tam = pegarTam(string);

    if(Palindromo(0, tam - 1, string)){
        printf("\nÉ Palindromo\n");
    }
    else{
        printf("\nNão é Palindromo");
    }

    return 0;
}