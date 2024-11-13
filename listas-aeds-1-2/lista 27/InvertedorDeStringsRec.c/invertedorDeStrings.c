#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nInvertedor de string recursva\n");
}

void lerString(char *string, int tam){
    
    printf("\nDigite uma string: ");
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
        char aux = string[i];
        string[i] = string[tam - i - 1];
        string[tam - i - 1] = aux;
    }
}

int main(){
    apresentacao();

    char string[100];
    

    lerString(string, sizeof(string));
    int tamain = pegarTam(string);  

    inverterString(string, tamain);

    printf("\nString invertida: ");
    printf("%s", string);

    return 0;
}