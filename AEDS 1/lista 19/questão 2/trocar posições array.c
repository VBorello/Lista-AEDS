#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
   printf("\nTrocador de posições expecificas do array\n\n");
}

int lerTamanho(){
    int tamanho;
    printf("digite o tamanho do array:");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerPosicao(int *a, int *b){
    printf("qual posicao quer:");
    scanf("%d", a);
    printf("qual posicao quer:");
    scanf("%d", b);
}

void lerArray(int v[], int tamanho){
    for(int i = 1; i < tamanho + 1; i++){
        printf("Digite o %d termo do array:", i);
        scanf("%d", &v[i]);
    }
}

void trocarPosicao(int v[], int tamanho){
    int a, b;

    lerPosicao(&a, &b);

    if(a < 0 || a  >= tamanho || b >= tamanho){
        printf("Posicoes invalidas");
    }
    else{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
        printf("array trocado:\n");
        for(int i = 1; i < tamanho + 1; i++){
            printf("%d", v[i]);
        }
        printf("\n");
    }
}

int main() {
    apresentacao();
    
    int tamanho = lerTamanho();
    int* v = (int*)malloc(tamanho * sizeof(int));
    
    lerArray(v, tamanho);
    
    trocarPosicao(v, tamanho);
    
    free(v);
    return 0;
}