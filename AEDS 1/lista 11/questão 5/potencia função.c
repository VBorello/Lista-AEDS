#include <stdio.h>

void apresentacao(){
    printf("\nPotenciacao funcao\n\n");
}

int potenciacao(int base, int expoente){
    int resultado = 1;
    for(int i = 0; i < expoente; i++){
        resultado *= base;
    }
    return resultado;
}

int lerBase(){
    int base;
    printf("Digite a base:");
    scanf("%d", &base);
    return base;
}

int lerExpoente(){
    int expoente;
    printf("Digite o expoente:");
    scanf("%d", &expoente);
    return expoente;
}

void showResultado(int resultado){
    printf("Sua potenciacao e igual a: %d\n", resultado);
}


int main(){
    apresentacao();
    int valorBase = lerBase();
    int valorExpoente = lerExpoente();
    int resultadoPotencia = potenciacao(valorBase, valorExpoente);
    showResultado(resultadoPotencia);
    return 0;
}