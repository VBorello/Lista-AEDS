#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void apresentacao() {
    printf("\nShift + 1 (inserir valor no vetor na posicao x)\n\n");
}

void lerTam(int *tam) {
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", tam);
}

void lerPosicao(int *posicao) {
    printf("\nDigite a posição que será inserido no vetor: ");
    scanf("%d", posicao);
}

void shiftMais1(int *tam, int v[], int posicao){
    
    for (int i = *tam; i > posicao; i--){
        v[i] = v[i - 1];
    }
    (*tam)++; 
}

bool insira(int *tam, int v[], float x, int posicao){

    if (*tam < MAX && posicao >= 0 && posicao <= *tam){
        shiftMais1(tam, v, posicao);
        v[posicao] = x;
        return true;
    }
    return false;
}

void lerVetor(int tam, int v[]){

    for (int i = 0; i < tam; i++){
        printf("\nDigite o termo %d do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void printVetor(int tam, int v[]){

    printf("Vetor: ");
    for (int i = 0; i < tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    apresentacao();

    int tam;
    lerTam(&tam);

    int *v = (int *)malloc(MAX * sizeof(int));

    lerVetor(tam, v);
    printVetor(tam, v);

    float x;
    printf("\nDigite o valor a ser inserido: ");
    scanf("%f", &x);

    int posicao;
    lerPosicao(&posicao);

    if (insira(&tam, v, x, posicao)) {
        printf("Elemento inserido com sucesso!\n");
    } else {
        printf("Falha ao inserir o elemento. Posição inválida.\n");
    }

    printVetor(tam, v);

    free(v);

    return 0;
}
