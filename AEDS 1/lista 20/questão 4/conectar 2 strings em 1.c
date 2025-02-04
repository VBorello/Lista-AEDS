#include <stdio.h>
#include <stdlib.h>

#define tamanhoMax 100

void apresentacao(){
    printf("\nJuntador de duas strings em uma terceira\n\n");
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

void juntarStrs(char* str1, char* str2, char* str3) {
    lerString(str1, tamanhoMax);
    lerString(str2, tamanhoMax);

    int i = 0, j = 0;

    while (str1[i] != '\0') {
        str3[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        str3[i] = str2[j];
        i++;
        j++;
    }

    str3[i] = '\0';

    printf("Resultado da junção: %s\n", str3);
}

int main() {
    char string1[tamanhoMax];
    char string2[tamanhoMax];
    char string3[2 * tamanhoMax]; 

    juntarStrs(string1, string2, string3);

    return 0;
}