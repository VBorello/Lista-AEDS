#include <stdio.h>

#define tamanhoMax 100

void apresentacao(){
    printf("\nqtd de vogais na str completam um vetor\n\n");
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

void preencherVVogal(char *str, int v[]) {
    
    int i = 0;

    while (str[i] != '\0') {
        if(str[i] == 'a'){
            v[i] = 0;
        } 
        else if(str[i] == 'e'){
            v[i] = 1;
        }  
        else if(str[i] == 'i'){
            v[i] = 2;
        }
        else if(str[i] == 'o'){
            v[i] = 3;
        }
        else if(str[i] == 'u'){
            v[i] = 4;
        }    
        else{
            v[i] = -1;
        }
        i++;
    }
    for(int j = 0; j < i; j++){
        if(v [j] != -1 ){
            printf("%d ", v[j]);
        }
    }
    printf("\n");
}
    

int main() {
    char string[tamanhoMax];
    int v[tamanhoMax];
    
    apresentacao();
    lerString(string, tamanhoMax);
    preencherVVogal(string, v);

    return 0;
}