#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPeso ideal de uma vila sem Varialvel convensional\n\n");
}

void quantidade(int* habitantes){
    printf("Digite a quantidade de habitantes: ");
    scanf("%d", habitantes);
}

void lerPesosAlturas(int habitantes, float *alturas, char *sexo){

    for(int i = 0; i < habitantes; i++){
        printf("\nDigite a altura da %d° pessoa: ", i + 1);
        scanf("%f", &alturas[i]);
        printf("\nQual o sexo da %d° pessoa(M/F): ", i + 1);
        scanf(" %c", &sexo[i]);
    }

}

void calcularPesoIdeal(int habitantes, float *alturas, char *sexo, float *pesosIdeais){

    for(int i = 0; i < habitantes; i++){
        if(sexo[i] == 'f' || sexo[i] == 'F'){
            pesosIdeais[i] = (62.1 * alturas[i]) - 44.7;
        }
        else if(sexo[i] == 'm' || sexo[i] == 'M'){
            pesosIdeais[i] = (72.2 * alturas[i]) - 58;
        }
    }
}

void printPesosIdeais(int habitantes, float *pesosIdeais){

    for(int i = 0; i < habitantes; i++){
        printf("\nPessoa %d°:\n", i + 1);
        printf("Peso ideal: %.2f\n", pesosIdeais[i]);
    }
}


int main() {
    apresentacao();

    bool erro;
    int habitantes;

    do{
        quantidade(&habitantes);
        erro = (habitantes <= 0);
        if(erro){
            printf("\nNumero de pessoas inválido\n");
        }
        
    }while(erro);
    


    float *alturas = (float *)malloc(habitantes * sizeof(float));
    char *sexo = (char *)malloc(habitantes * sizeof(char));
    float *pesosIdeais = (float *)malloc(habitantes * sizeof(float));

    lerPesosAlturas(habitantes, alturas, sexo);
    calcularPesoIdeal(habitantes, alturas, sexo, pesosIdeais);
    printPesosIdeais(habitantes, pesosIdeais);

    free(alturas);
    free(sexo);
    free(pesosIdeais);

    return 0;
}