#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nintrodução Tp\n\n");
}

void CriarArq(){

    FILE* exemplo = fopen("exemplo.dat" ,"w");
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    fprintf(exemplo, "%d", idade);
    printf("\nGravado com sucesso.");

    fclose(exemplo);


    exemplo = fopen("exemplo.dat" ,"a");
    if (exemplo == NULL) {
        printf("Erro ao abrir o arquivo para apêndice.\n");
        return;
    }

    int idadeM, idadeP;

    printf("\nDigite a idade de sua mãe: ");
    scanf("%d", &idadeM);
    printf("\nDigite a idade de seu pai: ");
    scanf("%d", &idadeP);
    fprintf(exemplo, "\n%d\n%d", idadeM, idadeP);
    printf("\nGravado com sucesso.");

    fclose(exemplo);


    exemplo = fopen("exemplo.dat", "r");
    if (exemplo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    int valor; 

    printf("\nIdades lidas do arquivo:\n");

    while (fscanf(exemplo, "%d", &valor) == 1) {
        printf("%d\n", valor); 
    }

    fclose(exemplo);  
}

int main(){
    apresentacao();
    
    CriarArq();
    
    return 0;
}