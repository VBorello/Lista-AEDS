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

void inverterVetor(int tam, int v[tam]){
    
    for(int i = 0; i < tam / 2; i++){
        int vAux = v[i];
        v[i] = v[tam - i - 1];
        v[tam - i - 1] = vAux; 
    }
    
    printf("\nvetor invertido: ");
    for(int i = 0; i < tam; i++){
        
        printf("%d ", v[i]);
    }
}

int main(){
    apresentacao();

    int tamanaho;
    tamV(&tamanaho);

    int *v = (int *)malloc(tamanaho * sizeof(int));

    lerVetor(tamanaho, v);
    inverterVetor(tamanaho, v);

    return 0;
}
