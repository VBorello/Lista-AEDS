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
    
    if(string[0] == '\0'){
        return 0;
    }

    int tamanho = 0;
    if(string[0] != '\0'){
        tamanho = 1;
    }

    return tamanho + calcularTamanho(string + 1);

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
