#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSTR 100

void apresentacao(){
    printf("\nComparador de Strings\n\n");
}

void lerString(char *string, int tam){
    
    printf("\nDigite uma frase: ");
    fgets(string, tam, stdin);

    int i = 0;
    while (string[i] != '\0'){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
        i++;
    }
}

int pegarTam(char *str){
    
    int tam = 0;
    while(str[tam] != '\0'){
        tam++;
    }

    return tam;
}

bool compararStrings(char *str1, char *str2){

    int tam1 = pegarTam(str1);
    int tam2 = pegarTam(str2);

    bool iguais = true;
    if(tam1 != tam2){
        iguais = false;
    }

    for(int i = 0; i < tam1; i++){
        if(str1[i] != str2[i]){
            iguais = false;
        }
    }

    return iguais;
}

void printString(char *str){
    
    printf("\n%s\n", str);
}

int main(){
    apresentacao();

    char string1[100];
    char string2[100];

    lerString(string1, 100);
    lerString(string2, 100);

    if(compararStrings(string1, string2)){
        printf("\nAs strings são iguais! :)");
    }
    else{
        printf("\nAs strings são diferentes :(");
    }
    printf("\n");
    printString(string1);
    printString(string2);
    return 0;
}