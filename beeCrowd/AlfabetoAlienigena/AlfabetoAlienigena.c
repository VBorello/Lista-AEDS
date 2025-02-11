#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nAlfabeto Alienigena\n\n");
}

void lerKeys(char* keys, int* keyTam){
    printf("Digite as keys: ");
    scanf("%s", keys);  

    *keyTam = 0; 
    while (keys[*keyTam] != '\0'){  
        (*keyTam)++;
    }
}

void lerFrase(char* frases, int* fTam){
    char temp[100];
    printf("Digite a frase: ");
    fgets(temp, sizeof(temp), stdin);

    int j = 0;
    for(int i = 0; temp[i] != '\0'; i++){
        if (temp[i] != ' ' && temp[i] != '\n'){  
            frases[j] = temp[i]; 
            j++;
        }
    }
    frases[j] = '\0';  
    *fTam = j;  
}

void keysNaFrase(char* frases, char* keys, int fTam, int keyTam){
    
    int iguais = 0;
    for(int i = 0; i < keyTam; i++){
        for(int j = 0; j < fTam; j++){
            if(keys[i] == frases[j]){  
                iguais++;
            }
        }
    }

    printf("%d\n", iguais);
}

int main() {
    apresentacao();

    char keys[100];
    char frases[100];
    int keyTam, fTam;

    lerKeys(keys, &keyTam);

    while (getchar() != '\n'); 
    
    lerFrase(frases, &fTam);

    keysNaFrase(frases, keys, fTam, keyTam);

    return 0;
}