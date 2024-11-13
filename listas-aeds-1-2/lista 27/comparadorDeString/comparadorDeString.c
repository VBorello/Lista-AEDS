#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void apresentacao(){
    printf("\nComparador De Strings\n\n");
}

void lerStrings(char *string){
    
    printf("\nDigite uma frase: ");
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

bool stringComparar(char *string1, char *string2){

    int tam1 = pegarTam(string1);
    int tam2 = pegarTam(string2);

    bool iguais = true;
    
    if(tam1 != tam2){
        iguais = false;
    }

    for(int i = 0; i < tam1; i++){
        if(string1[i] != string2[i]){
            iguais = false;
        }
    }

    return iguais;
}

void printString(char *string){
    
    printf("\n");
    int tam = pegarTam(string);
    for(int i = 0; i < tam; i++){
        printf("%c", string[i]);
    }
    printf("\n");
}

int main(){
    apresentacao();

    char string[100];
    char string2[100];

    lerStrings(string);
    lerStrings(string2);

    if(stringComparar(string, string2)){
        printf("\nIguais\n");
    }
    else{
        printf("\nDiferentes\n");
    }

    printString(string);
    printString(string2);

    return 0;
}