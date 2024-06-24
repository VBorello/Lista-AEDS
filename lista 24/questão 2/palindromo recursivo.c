#include <stdio.h>
#include <string.h>
#include <ctype.h>

int PalindromoRec(const char *str, int inicio, int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (tolower(str[inicio]) != tolower(str[fim])) {
        return 0; 
    }
    return PalindromoRec(str, inicio + 1, fim - 1);
}

int main() {

    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (PalindromoRec(palavra, 0, strlen(palavra) - 1)) {
        printf("%s palíndromo.\n", palavra);
    } else {
        printf("%s não palíndromo.\n", palavra);
    }

    return 0;
}
