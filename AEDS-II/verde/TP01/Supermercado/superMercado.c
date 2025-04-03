#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void lerMercados(int* qtdMercados){
    scanf("%d", qtdMercados);
}

double calcularPrecos(int qtdMercados){

    double menorPreco = 1e9;

    for(int i = 0; i < qtdMercados; i++){
        double preco;
        int gramas;
        scanf("%lf %d", &preco, &gramas);
        

        double precoPorG = (preco / gramas) * 1000;

        if(precoPorG < menorPreco){
            menorPreco = precoPorG;
        }
    }

    return menorPreco;
}

int main(){

    int qtdMercados;
    lerMercados(&qtdMercados);

    double menorPreco = calcularPrecos(qtdMercados);

    printf("%.2lf\n", menorPreco);

    return 0;
}