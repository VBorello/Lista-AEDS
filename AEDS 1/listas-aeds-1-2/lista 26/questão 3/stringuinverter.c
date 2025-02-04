#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nInvertedor de Stringos\n\n");
}

void lerString(char *string, int tam){
    printf("\nDigite uma frase: ");
    fgets(string, tam, stdin);

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

void inverterString(char *string, int tam){
    
    for(int i = 0; i < tam / 2; i++){
        char auxiliar = string[i];
        string[i] = string[tam - i - 1];
        string[tam - i - 1] = auxiliar;
    }

    printf("\n%s", string);
}

bool palindromagem(char *string, int tam){
    
    bool palindromo = true;
    for(int i = 0; i < tam; i++){
        if(string[i] != string[tam - i - 1]){
            palindromo =  false;
        }
    }

    return palindromo;
}

int main(){
    apresentacao();

    char string[100];
    lerString(string, 100);

    int tamanho = pegarTam(string);
    inverterString(string, tamanho);
    
    printf("\n");
    if(palindromagem(string, tamanho)){
        printf("\nÉ palindromo pode comemorar");
    }
    else{
        printf("\nNo es palindrome fique amargo :( ");
    }


    return 0;
}