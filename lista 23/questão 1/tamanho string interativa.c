#include <stdio.h>

#define TAMANHO_MAX 100

void apresentacao() {
    printf("\nQuantidade de letras na string\n\n");
}

int calcularTamanhoString(const char *str) {
    int tamanho = 0;

    while (str[tamanho] != '\0') {
        tamanho++;
    }

    return tamanho;
}

void lerString(char *str, int tamanhoMAX) {
    printf("Digite uma palavra: ");
    fflush(stdin); 
    fgets(str, tamanhoMAX, stdin);

    int tamanho = calcularTamanhoString(str);
    if (str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

int main() {
    char string[TAMANHO_MAX];

    apresentacao();
    lerString(string, TAMANHO_MAX);

    int tamanho = calcularTamanhoString(string);

    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}