#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nPeso Ideal Pointer Malloc\n\n");
}

int *numPessoas() {
    int *n = (int*) malloc(sizeof(int));
    if(n == NULL){
        printf("erro");
        exit (1);
    }
    printf("\nDigite quantas sao as pessoas:");
    scanf(" %d", n);
    return n;
}

char *leiaGenero() {
    char *genero = (char*) malloc(sizeof(char));
    if (genero == NULL){
        printf("Erro");
        exit(1);
    }
    printf("\nDigite seu genero (m/f):");
    scanf(" %c", genero);
    return genero;
}

float *leiaAltura() {
    float *altura = (float*)malloc(sizeof(float));
    if(altura == NULL){
        printf("erro");
        exit(1);
    }
    printf("\nDigite sua altura:");
    scanf(" %f", altura);
    return altura;
}

float *calculaPesoIdeal(float altura, char genero) {
    float *pesoIdeal = (float*)malloc(sizeof(float));
    if(pesoIdeal == NULL){
        printf("erro");
        exit(1);
    }
    if (genero == 'm' || genero == 'M') {
        *pesoIdeal = (72.2 * altura) - 58;
    } else if (genero == 'f' || genero == 'F') {
        *pesoIdeal = (62.1 * altura) - 44.7;
    } else {
        printf("Genero invalido!\n");
        *pesoIdeal = -1; 
    }
    return pesoIdeal;
}

int main() {

    apresentacao();

    int *pessoas = numPessoas();

    for (int i = 0; i < *pessoas; i++) {
        char *genero = leiaGenero();
        float *altura = leiaAltura();
        float *pesoIdeal = calculaPesoIdeal(*altura, *genero);

        if (*pesoIdeal != -1) {
            printf("O peso ideal dessa pessoa e de: %.2f kg\n", *pesoIdeal);
        }
        free(genero);
        free (altura);
        free (pesoIdeal);
    }
    free (pessoas);

    return 0;
}