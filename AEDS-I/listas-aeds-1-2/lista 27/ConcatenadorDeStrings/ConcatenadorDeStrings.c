#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    system("clear");
    printf("\nConcatenador De strings\n\n");
}

void lerStrings(int tam, char *string){
    
    printf("Digite uma frase: ");
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
    while (string[tam] != '\0'){
        tam++;
    }

    return tam;
}

void concatenador(char *string1, char *string2){

    int tam1 = pegarTam(string1);
    int tam2 = pegarTam(string2);

    int tam3 = tam1 + tam2 + 1;
    char concatenada[tam3];

    for(int i = 0; i < tam1; i++){
        concatenada[i] = string1[i];
    }

    for(int i = 0; i < tam2; i++){
        concatenada[tam1 + i] = string2[i];
    }

    concatenada[tam3 - 1] = '\0';
    printf("String concatenada: %s\n", concatenada);

}

int main(){
    apresentacao();

    char string[100];
    char string2[100];

    lerStrings(100, string);
    lerStrings(100, string2);

    concatenador(string, string2);

    return 0;
}
