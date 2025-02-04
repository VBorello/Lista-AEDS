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

void inverterString(int inicio, int fim, char *string){

    if(inicio >= fim){
        return;
    }

    char aux = string[inicio];
    string[inicio] = string[fim];
    string[fim] = aux;

    return inverterString(inicio + 1, fim - 1, string);
}

int main(){
    apresentacao();

    char string[100];
    

    lerString(string, sizeof(string));
    int tamain = pegarTam(string);  

    inverterString(0, tamain - 1, string);

    printf("\nString invertida: ");
    printf("%s", string);

    return 0;
}