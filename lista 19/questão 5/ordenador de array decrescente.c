#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nOrdenador de array decrescente\n\n");
}

int lerComprimento(){
    int comprimento;
    printf("Digite o tamanho do array: ");
    scanf("%d", &comprimento);
    return comprimento;
}

void lerArray(int v[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite o %dº valor desse array: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void decrescente(int v[], int tamanho){
    int aux;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(v[j] < v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    printf("\no array em ordem decrescente e:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

void crescente(int v[], int tamanho){
    int aux;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    printf("\no array em ordem crescente e:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

char escolha(){
    
    bool erro;
    char cOuD;
    do{
        printf("\nQuer o array em que ordem:");
        scanf(" %c", &cOuD);
        erro = (cOuD != 'c' && cOuD != 'C' && cOuD != 'd' && cOuD != 'D');
        if(erro){
            printf("Digite uma opcao valida(d/c)\n");
        }
    }while(erro);
    
    return cOuD;
}

int main(){
    
    apresentacao();

    int tamanho = lerComprimento();
    int* v = (int *)malloc(sizeof(int));

    lerArray(v, tamanho);

    char cOuD = escolha();
    if(cOuD == 'd' || cOuD == 'D'){
        decrescente(v, tamanho);
    }
    else if(cOuD == 'c' || cOuD == 'C'){
        crescente(v, tamanho);
    }
    
    free(v);
    return 0; 
}