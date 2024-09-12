#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nDias vividos ate hoje\n\n");
}

void lerIdade(int* idade){
    printf("Digite a sua Idade: ");
    scanf("%d", idade);
}

void lerData(int* dia, int* mes, int* ano, int* dAno, int* dDia, int* dAno){
    int bissexto;
    printf("Digite o dia mes e ano (dd/mm/aaaa): ");
    scanf("%d %d %d", dia, mes, ano);

    dAno = 365;
    dMes = 30; 

    if((*ano % 4 == 0 && *ano % 100 != 0) || (*ano % 400 == 0)){
        bissexto = 366;
        if(*mes == 2){
            dMes = 29;
        } 
    }

    if(*mes = 1){
        dMes = 31;
    }
    else if(*mes = 2){
        dMes = 28;
    }
    else if(*mes = 3){
        dMes = 30;
    }
    else if(*mes = 4){
        dMes = 30;
    }
    else if(*mes = 5){
        dMes = 31;
    }
    else if(*mes = 6){
        dMes = 29;
    }
    else if(*mes = 7){
        dMes = 31;
    }
    else if(*mes = 8){
        dMes = 31;
    }
    else if(*mes = 9){
        dMes = 30;
    }
    else if(*mes = 10){
        dMes = 31;
    }
    else if(*mes = 11){
        dMes = 30;
    }
    else if(*mes = 12){
        dMes = 31;
    }    
}

void calcularDias(int* dia, int* mes, int* ano, int* idade){
    while ()
    {
    
    }
    
}
