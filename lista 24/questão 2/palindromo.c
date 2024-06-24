#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPalindromoIterativo(const char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return 0; 
        }
        inicio++;
        fim--;
    }
    return 1; 
}

int main() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (ehPalindromoIterativo(palavra)) {
        printf("%s palíndromo.\n", palavra);
    } else {
        printf("%s não palíndromo.\n", palavra);
    }

    return 0;
}
