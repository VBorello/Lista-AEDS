#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nSequencia K-ésima del Fibonacci\n\n");
}

void lerQtdTermos(int *termos){
    
    printf("quantos termos de fibonacci serão?");
    scanf("%d", termos);
}

void lerTermoInicial(int *inicio){
    
    printf("\nQual será o primeiro valor da sequência?");
    scanf("%d", inicio);
}

void calcularSequencia(int inicio, int termos){

    int primeiro = inicio;
    int segundo = primeiro + 1;
    int resultado;

      for(int i = 2; i < termos; i++) {
        resultado = primeiro + segundo;
        printf("%d ", resultado);
        primeiro = segundo;
        segundo = resultado;
    }
    printf("\n");
}   


int main(){
    apresentacao();

    int termos;
    int primeiro;
    lerQtdTermos(&termos);
    lerTermoInicial(&primeiro);

    calcularSequencia(primeiro, termos);

    return 0;
}
