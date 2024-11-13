#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nInvertedor de vetores\n\n");
}

void tamV(int *tam){

    printf("digite o tamain do veto: ");
    scanf("%d", tam);
}

void lerVetor(int tam, int v[tam]){

    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor [%d] do vetor: ", i + 1);
        scanf("%d", &v[i]);
    }
}

void inverterVetorRec(int v[], int fim, int inicio){
    
    if(inicio >= fim){
        return;
    }
    
    int aux = v[inicio];
    v[inicio] = v[fim];
    v[fim] = aux;

    inverterVetorRec(v, inicio + 1, fim - 1);
}

int main(){
    apresentacao();

    int tamanaho;
    tamV(&tamanaho);

    int *v = (int *)malloc(tamanaho * sizeof(int));

    lerVetor(tamanaho, v);
    inverterVetorRec(v, tamanaho - 1, 0);

    printf("\nvetor invertido: ");
    for(int i = 0; i < tamanaho; i++){
        
        printf("%d ", v[i]);
    }

    return 0;
}
