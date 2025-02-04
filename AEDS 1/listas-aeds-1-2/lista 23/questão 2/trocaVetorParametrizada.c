#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nTroca Parametrizada de posições em um Vetor\n\n");
}

void lerTam(int* tam){
    printf("Digite o tamanho do vetor: ");
    scanf("%d", tam);
}

void lerVetor(int tam, int vetor[tam]){

    for(int i = 0; i < tam; i++){
        printf("\nDigite o %d termo do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void lerTrocas(int tam, int* p1, int* p2){
    
    bool erro;

    do{
        printf("\nDigite as posições de troca(espaçado): ");
        scanf("%d %d", p1, p2);
        
        erro = ((*p1 > tam || *p2 > tam) && (*p1 < 0 || *p2 < 0));

        if(erro){
            printf("\nposição inválida");
        } 
    
    }while(erro);
}

void trocarPosicoes(int tam, int vetor[tam], int p1, int p2){

    printf("\nAntes: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    int temp = vetor[p1];
    vetor[p1] = vetor[p2];
    vetor[p2] = temp;

    printf("\nDepois: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){
    apresentacao();

    int tamanho;
    lerTam(&tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    lerVetor(tamanho, vetor);

    int p1, p2;
    lerTrocas(tamanho, &p1,&p2);

    p1--;
    p2--;

    trocarPosicoes(tamanho, vetor, p1, p2);

    free(vetor);

    return 0;
}