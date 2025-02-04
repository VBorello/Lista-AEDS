#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nTroca Menor Valor para primeira posição de um vetor\n\n");
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

void ordenarCrescente(int tam, int vetor[tam]){

    printf("\nAntes: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    for(int i = 0; i < tam - 1; i++){
        int indiceMin = i;
        for(int j = i + 1; j < tam; j++){
            if(vetor[j] < vetor[indiceMin]){
                indiceMin = j;
            }
        }

        int aux = vetor[i];
        vetor[i] = vetor[indiceMin];
        vetor[indiceMin] = aux;
    }


    printf("\nDepois: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

void ordenarDecrescente(int tam, int vetor[tam]){

    printf("\nAntes: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    for(int i = 0; i < tam - 1; i++){
        int indiceMax = i;
        for(int j = i + 1; j < tam; j++){
            if(vetor[j] > vetor[indiceMax]){
                indiceMax = j;
            }
        }

        int aux = vetor[i];
        vetor[i] = vetor[indiceMax];
        vetor[indiceMax] = aux;
    }


    printf("\nDepois: ");
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){
    apresentacao();


    int tam;
    lerTam(&tam);

    int* vetor = (int *)malloc(tam * sizeof(int));
    lerVetor(tam, vetor);

    int opcao;
    bool erro;
    do{
        printf("\nQual ordem que seu vetor?\n1- Crescente\n2- Decrescente\n: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            ordenarCrescente(tam, vetor);
        }
        else if(opcao == 2){
            ordenarDecrescente(tam, vetor);
        }
        
        erro = (opcao != 1 && opcao != 2);        
        
        if(erro){
            printf("\nopção inválida");
        }

    }while(erro);

    free(vetor);

    return 0 ;
}