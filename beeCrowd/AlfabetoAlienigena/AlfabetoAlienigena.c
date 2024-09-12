#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nAlfabeto Alienigena\n\n");
}

void lerKeys(char* keys, int* Ktam){
    printf("Digite as keys: ");
    scanf("%s", keys);  

    *Ktam = 0; 
    while (keys[*Ktam] != '\0'){  
        (*Ktam)++;
    }
}

void lerFrase(char* frases, int* Ftam){
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
    *Ftam = j;  
}

void keysNaFrase(char* frases, char* keys, int Ftam, int Ktam){
    
    int iguais = 0;
    for(int i = 0; i < Ktam; i++){
        for(int j = 0; j < Ftam; j++){
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
    int Ktam, Ftam;

    lerKeys(keys, &Ktam);

    while (getchar() != '\n'); 
    
    lerFrase(frases, &Ftam);

    keysNaFrase(frases, keys, Ftam, Ktam);

    return 0;
}