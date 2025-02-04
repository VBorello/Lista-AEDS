#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EPSILON 0.0001 //Para não dar merda ao comparar float com float

void apresentacao(){
    printf("\nVerificador de triangulos equilateros em um vetor\n\n");
}

typedef struct{
    
    float l1;
    float l2;
    float l3;

}Triangulo;

int pegarTam(){

    int tam;
    printf("\nQuantos Triangulos seu vetor possui: ");
    scanf("%d", &tam);

    return tam;
}

void lerVetor(int tam, Triangulo lados[tam]) {
    
    for (int i = 0; i < tam; i++) {
        printf("\nDigite os lados do triângulo %d:\n", i + 1);
        printf("Lado 1: ");
        scanf("%f", &lados[i].l1);
        printf("Lado 2: ");
        scanf("%f", &lados[i].l2);
        printf("Lado 3: ");
        scanf("%f", &lados[i].l3);
    }
}

int qtdEquliateros(int tam, Triangulo lados[tam]){
    
    int qtd = 0;
    for(int i = 0;  i < tam; i++){
        if ((lados[i].l1 - lados[i].l2 < EPSILON && lados[i].l2 - lados[i].l1 < EPSILON) &&
            (lados[i].l2 - lados[i].l3 < EPSILON && lados[i].l3 - lados[i].l2 < EPSILON)) {
            qtd++;
        }
    }

    return qtd;
}

int main(void){
    apresentacao();

    int tamanho = pegarTam();
    
    Triangulo lados[tamanho];

    lerVetor(tamanho, lados);
    int quantidadeEquilatera = qtdEquliateros(tamanho, lados);
    
    printf("\nA quantidade de triangulos equilateros em seu vetor é de: %d", quantidadeEquilatera);

    return 0;
}