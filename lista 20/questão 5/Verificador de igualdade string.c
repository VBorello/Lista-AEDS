#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao() {
    printf("\nVerificador de Igualdade de Strings\n\n");
}

int qtdPalavras() {
    int palavras = 2;
    return palavras;
}

void lerStr(char *str, int tamanho) {
    printf("Digite uma palavra: ");
    scanf("%s", str);
}

void printStr(char *str) {
    printf("%s\n", str);
}

int strTamanho(char *str) {
    int tamanho = 0;
    while (str[tamanho] != '\0') {
        tamanho++;
    }
    return tamanho;
}

bool compararStrs(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}

int main() {
    apresentacao();
    int n = qtdPalavras();

    char **palavras = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        palavras[i] = (char *)malloc(100 * sizeof(char));
        lerStr(palavras[i], 100);
    }

    printf("\nPalavras lidas:\n");
    for (int i = 0; i < n; i++) {
        printStr(palavras[i]);
    }

    bool iguais = true;
    for (int i = 1; i < n; i++) {
        if (!compararStrs(palavras[0], palavras[i])) {
            iguais = false;
            break;
        }
    }

    if (iguais) {
        printf("\nAs palavras sao iguais.\n");
    } else {
        printf("\nAs palavras nao sao iguais.\n");
    }

    for (int i = 0; i < n; i++) {
        free(palavras[i]); 
    }
    free(palavras); 

    return 0;
}
