#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nVetor Para Sting de vogais\n\n");
}

void lerTam(int *tam){
    
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", tam);
}

void lerVetor(int tam, int v[tam]){

    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor %d do vetor(1 a 5): ", i + 1);
        scanf("%d", &v[i]);
    }
}


void converterParaString(int tam, int v[tam], char *string){
    
    for(int i = 0; i < tam; i++){
        if(v[i] == 1){
            string[i] = 'a';
        }
        else if(v[i] == 2){
            string[i] = 'e';
        }
        else if(v[i] == 3){
            string[i] = 'i';
        }
        else if(v[i] == 4){
            string[i] = 'o';
        }
        else if(v[i] == 5){
            string[i] = 'u';
        }
    }
}

void printV(int tam, int v[tam]){
    printf("\nvetor:\n\n ");
    for(int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void printStr(int tam, char *str){
    printf("\nstring:\n\n ");
    for(int i = 0; i < tam; i++){
        printf("%c ", str[i]);
    }
}

int main(){
    apresentacao();
    
    int tamanho;
    lerTam(&tamanho);
    char string[100];

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    
    lerVetor(tamanho , vetor);
    converterParaString(tamanho, vetor, string);

    printV(tamanho, vetor);
    printStr(tamanho, string);

    free(vetor);

    return 0;
}

