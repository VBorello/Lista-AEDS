#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nDias vividos até hoje\n\n");
}

void lerDias(int* dia, int* mes, int* ano){
    printf("Digite o dia/mes/ano (espaçado): ");
    scanf("%d %d %d", dia, mes, ano);
}

bool bissexto(int* dia, int* mes, int* ano){
    if ((*ano % 4 == 0 && *ano % 100 != 0) || (*ano % 400 == 0)){
        return true;
    }

    return false;
       
}

bool validarData(int* dia, int* mes, int* ano){
    bool dataValida = true;

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1 ||
        (mes == 2 && ((bissexto(&ano) && dia > 29) || (!bissexto(&ano) && dia > 28))) ||
        (mes == 4 && dia > 30) ||
        (mes == 6 && dia > 30) ||
        (mes == 9 && dia > 30) ||
        (mes == 11 && dia > 30)) {
        dataValida = false;
           
    }
    return dataValida;
}
   