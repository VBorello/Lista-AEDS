#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void apresentacao(){
    printf("\nVetor invertido?\n\n");
}

void letTam(int* tam){
    printf("qual tamanho do vetor: ");
    scanf("%d", tam);
}

void lerVetores(int *v1, int *v2, int tam){

    for(int i = 0; i < tam; i++){
        printf("digite o %d valor do 1° vetor: ", i + 1);
        scanf("%d", &v1[i]);
    }   
    printf("\n");
    for(int i = 0; i < tam; i++){
        printf("digite o %d valor do 2° vetor: ", i + 1);
        scanf("%d", &v2[i]);
    }
   
}

void invertedor(int *v1, int *v2, int tam){

    int aux;
    for(int i = 0; i < tam / 2; i++){
        aux = v1[i];
        v1[i] = v1[tam - 1 - i];
        v1[tam - 1 - i] = aux;
    }

    printf("\nVetor 1 invertido: ");
    for(int i = 0; i < tam; i++) {
        printf("%d ", v1[i]);
    }
    printf("\n");

    bool ingual = true;
    for(int i = 0; i < tam; i++) {
        if(v2[i] != v1[i]) {
            ingual = false;
            break;
        }
    }

    if(ingual) {
        printf("\nO 2° é o inveros\n");
    } else {
        printf("\nO 2° é inverso nada\n");
    }
}

int main() {

    apresentacao();
    
    int tamanho;
    letTam(&tamanho);

    int* v1 = (int *)malloc(tamanho * sizeof(int));
    int* v2 = (int *)malloc(tamanho * sizeof(int));

    if (v1 == NULL || v2 == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    lerVetores(v1, v2, tamanho);

    invertedor(v1, v2, tamanho);
    
    free(v1);
    free(v2);

    return 0;
}