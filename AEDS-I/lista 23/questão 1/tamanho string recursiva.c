#include <stdio.h>

#define TAMANHO_MAX 100

void apresentacao() {
    printf("\nQuantidade de letras na string Abordagem Recursiva\n\n");
}

int tamanhoRecursivo(const char *str, int tamanho) {
    if (str[tamanho] == '\0') {
        return tamanho;
    }
    return tamanhoRecursivo(str, tamanho + 1);
}

void lerString(char *str, int tamanhoMAX) {
    printf("Digite uma palavra: ");
    fflush(stdin); 
    fgets(str, tamanhoMAX, stdin);

    int tamanho = tamanhoRecursivo(str, 0);
    if (str[tamanho - 1] == '\n') {
        str[tamanho - 1] = '\0';
    }
}

int main() {
    char string[TAMANHO_MAX];

    apresentacao();
    lerString(string, TAMANHO_MAX);

    int tamanho = tamanhoRecursivo(string, 0);

    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}
