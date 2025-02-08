#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EPSILON 0.0001 //Para não dar merda ao comparar float com float

void apresentacao(){
    printf("\nVerificador de triangulos equilateros/isoceles/escalenos em um vetor\n\n");
}

typedef struct{
    
    float l1;
    float l2;
    float l3;

}Triangulo;

int tam = 0;
Triangulo *lados = NULL;

int pegarTam(){

    int tam;
    printf("\nQuantos Triangulos seu vetor possui: ");
    scanf("%d", &tam);

    return tam;
}

void lerVetor() {
   
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

bool saoIguais(float a, float b) {
    return (a - b < EPSILON && b - a < EPSILON);
}

int qtdEquilateros(){
    
    int qtd = 0;
    for (int i = 0; i < tam; i++) {
        if (saoIguais(lados[i].l1, lados[i].l2) && saoIguais(lados[i].l2, lados[i].l3)) {
            qtd++;
        }
    }

    return qtd;
}

int qtdIsoceles(){

    int qtd = 0;
    for (int i = 0; i < tam; i++) {
        if ((saoIguais(lados[i].l1, lados[i].l2) && !saoIguais(lados[i].l1, lados[i].l3)) ||
            (saoIguais(lados[i].l1, lados[i].l3) && !saoIguais(lados[i].l1, lados[i].l2)) ||
            (saoIguais(lados[i].l2, lados[i].l3) && !saoIguais(lados[i].l1, lados[i].l2))) {
            qtd++;
        }
    }
   
    return qtd;
}

int qtdEscalenos(){

    int qtd = 0;
    for (int i = 0; i < tam; i++) {
        if (!saoIguais(lados[i].l1, lados[i].l2) &&
            !saoIguais(lados[i].l1, lados[i].l3) &&
            !saoIguais(lados[i].l2, lados[i].l3)) {
            qtd++;
        }
    }

    return qtd;
}


int main(void){
    apresentacao();

    int opcao;

    do{
        printf("\nMenu:\n\n0- sair do programa\n1- registrar triangulo\n2- quantidade de equilateros\n3- quantidade de isoceles\n4- quantidade de escalenos\n: ");
        scanf("%d", &opcao); 

        switch (opcao){

            case 0:{
                printf("\nSaindo.");
                free(lados);
                break;
            }

            case 1:{
                tam = pegarTam();
                lados = (Triangulo *)malloc(tam * sizeof(Triangulo));  // Aloca memória para os triângulos
                if (lados == NULL) {
                    printf("\nErro de alocação de memória.\n");
                    return 1;
                }
                lerVetor();
                
                break;
            }

            case 2:{
                int quantidadeEquilatera = qtdEquilateros();
                printf("\nA quantidade de triângulos equiláteros é: %d\n", quantidadeEquilatera);
                
                break;
            }

            case 3:{
                int quantidadeIsoceles = qtdIsoceles();
                printf("\nA quantidade de triangulos isoceles em seu vetor é de: %d", quantidadeIsoceles);

                break;
            }

            case 4:{
                int quantidadeEscalena = qtdEscalenos();
                printf("\nA quantidade de triangulos escalenos em seu vetor é de: %d", quantidadeEscalena);

                break;
            }
            
            default:{
                printf("\nOpção inválida!\n");
                break;
            }
        }

    }while(opcao != 0);

    return 0;
}