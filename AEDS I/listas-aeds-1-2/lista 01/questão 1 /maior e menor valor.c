#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    
    printf("\nIdentificador de maior valor\n\n");
}

void lerTermos(int* termos){

    printf("Digite a quantidade de termos: ");
    scanf("%d", termos);
}

void lerValores(int* valores, int termos){

    for (int i = 0; i < termos; i++) {
        printf("Digite o %dº termo: ", i + 1);
        scanf("%d", &valores[i]);
        if(i == termos - 1){
            printf("\n");
        }
    }
}

int identificarMaior(int* valores, int termos){
    
    int maior = valores[0];

    for (int i = 1; i < termos; i++) {
        if (valores[i] > maior) {
            maior = valores[i];
        }
    }

    return maior;
}

int identificarSegundoMaior(int* valores, int termos){

    int maior = valores[0];
    int segundoMaior = valores[0];

    for(int i = 1; i < termos; i++){
        
        if(valores[i] > maior){
            segundoMaior = maior;
            maior = valores[i];
        }
        else if(valores[i] > segundoMaior && valores[i] != maior){
            segundoMaior = valores[i];
        }
    }

    return segundoMaior;
}

int identificarMenor(int* valores, int termos){
    
    int menor = valores[0];

    for (int i = 1; i < termos; i++) {
        if (valores[i] < menor) {
            menor = valores[i];
        }
    }

    return menor;
}

int identificarSegundoMenor(int* valores, int termos){

    int menor = valores[0];
    int segundoMenor = valores[0];

    for(int i = 1; i < termos; i++){
        
        if(valores[i] < menor){
            segundoMenor = menor;
            menor = valores[i];
        }
        else if(valores[i] < segundoMenor && valores[i] != menor){
            segundoMenor = valores[i];
        }
    }

    return segundoMenor;
}

void printTermos(int* valores, int termos){

    printf("\nos valores são:");
    for(int i = 0; i < termos; i++){
        printf("%d ", valores[i]);
        if(i == termos - 1){
            printf("\n");
        }
    }
}

int main() {
    apresentacao();

    int termos;
    lerTermos(&termos);

    int* valores = (int*) malloc(termos * sizeof(int));
    if (valores == NULL){
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    lerValores(valores, termos);
    printTermos(valores, termos);

    int maior = identificarMaior(valores, termos);
    int segundoMaior = identificarSegundoMaior(valores, termos);
    int menor = identificarMenor(valores, termos);
    int segundoMenor = identificarSegundoMenor(valores, termos);
    printf("\nO maior valor é: %d\nO segundo maior é: %d", maior, segundoMaior);
    printf("\nO menor valor é: %d\nO segundo menor é: %d", menor, segundoMenor);
    
    free(valores);

    return 0;
}
