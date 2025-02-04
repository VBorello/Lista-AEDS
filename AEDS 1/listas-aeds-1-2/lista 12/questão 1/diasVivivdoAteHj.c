#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nDias Vividos até hoje\n\n");
}

void lerIdade(int* idade){
    printf("Digite sua idade: ");
    scanf("%d", idade);
}

void lerData(int* dia, int* mes, int* ano){
    printf("Digite o dia do seu aniversário (dd mm aaaa): ");
    scanf("%d %d %d", dia, mes, ano);
}

bool verSeEBissexto(int ano){
    
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    }
    return false;
}

int diasNoMes(int mes, int ano){
    
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            switch (verSeEBissexto(ano)) {
                case true:
                    return 29;  
                case false:
                    return 28;  
            }
        default:
            return 0;
    }
}

int calcularDiasVividos(int dia, int mes, int ano, int idade){
    int diasVividos = 0;

    for (int i = 0; i < idade; i++) {
        if (verSeEBissexto(ano + i)) {
            diasVividos += 366;
        } else {
            diasVividos += 365;
        }
    }

    int diasAnoAtual = 0;
    for (int i = 1; i < mes; i++) {
        diasAnoAtual += diasNoMes(i, ano);
    }
    diasAnoAtual += dia;

    diasVividos -= diasAnoAtual;

    return diasVividos;
}

int main(){
    apresentacao();

    int dia, mes, ano;
    int idade;

    lerData(&dia, &mes, &ano);
    lerIdade(&idade);

    int diasVividos = calcularDiasVividos(dia, mes, ano, idade);

    printf("\nAté hoje, você já viveu aproximadamente %d dias.\n", diasVividos);

    return 0;
}
