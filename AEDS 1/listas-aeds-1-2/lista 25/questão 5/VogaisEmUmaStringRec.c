#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 100

void apresentacao() {
    printf("\nVogais na string Recursiva\n\n");
}

void lerString(char *string, int tam){
    printf("Digite uma palavra: ");
    scanf("%s", string);
}

int contarVogais(char *string) {
    
    if(string[0] == '\0'){
        return 0;
    }

    char letra = string[0];
    int vogal = (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');

    return vogal + contarVogais(string + 1);

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
