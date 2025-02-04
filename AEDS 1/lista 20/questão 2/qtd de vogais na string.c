#include <stdio.h>

#define tamanhoMax 100

void apresentacao() {
    printf("\nQuantidade de letras na string\n\n");
}

void lerString(char *str, int tamanhoMAX) {
    printf("Digite uma palavra: ");
    fflush(stdin); 
    fgets(str, tamanhoMAX, stdin);

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
}

int qtdVogal(char *str) {
    int vogal = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
            vogal++;
        }
        i++;
    }
    return vogal;
}

int main() {
    char string[tamanhoMax];
    apresentacao();
    lerString(string, tamanhoMax);
    int vogais = qtdVogal(string);
    printf("Número de vogais: %d\n", vogais);
    return 0;
}