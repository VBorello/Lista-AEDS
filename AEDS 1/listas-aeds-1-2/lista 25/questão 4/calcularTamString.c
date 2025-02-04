#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 100

void apresentacao() {
    printf("\nCalcular Tamanho da String\n\n");
}

void lerString(char *string, int tam){
    printf("Digite uma palavra: ");
    scanf("%s", string);
}

int calcularTamanho(char *string) {
    int tam = 0;
    while (string[tam] != '\0') {
        tam++;
    }
    return tam;
}

int main() {
    apresentacao();

    char *string = (char *)malloc(MAXSTR * sizeof(char));

    lerString(string, MAXSTR);

    int tamanho = calcularTamanho(string);

    printf("\nEssa string tem: %d caracteres\n", tamanho);

    free(string); 
    return 0;
}
