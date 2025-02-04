#include <stdio.h>
#include <stdlib.h>

void apresentacao(){

    printf("\nVogais na string representada no vetor\n\n");
}

void lerString(char *string){

    printf("\nDigite uma palavra: ");
    scanf("%s", string);
}

int pegarTam(char* string){

    int tam = 0;
    while(string[tam] != '\0'){
        tam++;
    }

    return tam;
}

void vogaisVetor(char *string, int vetor[5]){

    for(int i = 0; i < 5; i++){
        vetor[i] = 0;
    }

    int tam = pegarTam(string);
    for(int i = 0; i < tam; i++){
        if(string[i] == 'a' || string[i] == 'A'){
            vetor[0]++;
        }
        else if(string[i] == 'e'){
            vetor[1]++;
        }
        else if(string[i] == 'i'){
            vetor[2]++;
        }
        else if(string[i] == 'o'){
            vetor[3]++;
        }
        else if(string[i] == 'u'){
            vetor[4]++;
        }
    }
}

void printVogais(char *string, int vetor[5]) {
    printf("\nA palavra '%s' possui:\n", string);
    printf("a: %d\n", vetor[0]);
    printf("e: %d\n", vetor[1]);
    printf("i: %d\n", vetor[2]);
    printf("o: %d\n", vetor[3]);
    printf("u: %d\n", vetor[4]);
}
int main(){
    apresentacao();

    char string[100];
    lerString(string);

    pegarTam(string);

    int vetor[5];

    vogaisVetor(string, vetor);
    printVogais(string, vetor);

    return 0;
}
