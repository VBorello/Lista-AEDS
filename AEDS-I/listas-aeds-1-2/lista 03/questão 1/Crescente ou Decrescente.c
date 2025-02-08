#include <stdlib.h>
#include <stdio.h>

void lerQtd(int* qtd){
    
    printf("Digite a quantidade de valores:");
    scanf("%d", qtd);
}

void lerValores(int* valores, int qtd){
    
    for(int i = 0; i < qtd; i++){
        printf("Digite o %d valor:", i + 1);
        scanf("%d", &valores[i]);
    }
}

void decrescente(int* valores, int qtd){
    for(int i = 0; i < qtd; i++){
        for(int j = i + 1; j < qtd; j++){
            if(valores[i] < valores[j]){
                int aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
    }

    printf("\nValores em ordem decrescente: ");
    for(int i = 0; i < qtd; i++){
        printf("%d ", valores[i]);
    }
    printf("\n");
}

void crescente(int* valores, int qtd){
    for(int i = 0; i < qtd; i++){
        for(int j = i + 1; j < qtd; j++){
            if(valores[i] > valores[j]){
                int aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;
            }
        }
    }

    printf("\nValores em ordem crescente: ");
    for(int i = 0; i < qtd; i++){
        printf("%d ", valores[i]);
    }
    printf("\n");
}

void menu(){
    printf("\nDecrescente ou Crescente\n\n");
    char opcao;

    int qtd;
    lerQtd(&qtd);

    int* valores = (int*)malloc(qtd * sizeof(int));
    if(valores == NULL){
        printf("Erro ao alocar");
        return (1);
    }

    lerValores(valores, qtd);
    
    printf("digite qual ordem quer(d/c):");
    scanf(" %c", opcao);

    if(opcao == 'C'){
        opcao = 'c';
    }
    else if(opcao == 'D'){
        opcao = 'd';
    }

    switch (opcao)
    {
    case 'd':{
        decrescente(valores, qtd);

    }
        break;
    case 'c':{
        crescente(valores, qtd);
    }
        break;
    
    default:
        printf("opção inválida");
        break;
    }

    free(valores);
    x

int main(){

    menu();

    return 0;
}