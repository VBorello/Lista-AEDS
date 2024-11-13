#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 100

void apresentacao() {
    printf("\nVogias na string\n\n");
}

void lerString(char *string, int tam){
    printf("Digite uma palavra: ");
    scanf("%s", string);
}

int contarVogais(char *string) {
    int vogal = 0;  
    
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {
            vogal++;
        }
    }

    return vogal;
}

int main() {
    apresentacao();

    char *string = (char *)malloc(MAXSTR * sizeof(char));

    lerString(string, MAXSTR);

    int vogais = contarVogais(string);

    printf("\nEssa string tem: %d vogais\n", vogais);

    free(string); 
    return 0;
}
