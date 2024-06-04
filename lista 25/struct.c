#include <stdio.h>
#include <stdlib.h>

#define max 2

typedef struct{
    char nome[50];
    float nota;
} ALUNOS;

int main(){

    ALUNOS *a[max];

    for(int i = 0; i < max; i++){
        a[i] = (ALUNOS *)malloc(sizeof(ALUNOS));
        if(a[i] == NULL){
            printf("erro ao alocar");
            return 1;
        }
        printf("\nNome:");
        fflush(stdin);
        fgets(a[i]->nome, 50, stdin);
        printf("\n Nota:");
        scanf("%f", &a[i]->nota);
    }
    
    for(int i = 0; i < max; i++){
        printf("\n nome: %s", a[i]->nome);
        printf("\n nota: %.2f", a[i]->nota);
    }
        
    return 0;
}