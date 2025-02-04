#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nQuantos dias tem esse mês?\n\n");
}

int lerMes(){
    int mes;
    bool erro;
    do {
        printf("Digite o mês (1-12): ");
        scanf("%d", &mes);
        erro = (mes > 12 || mes < 1);
        if(erro){
            printf("Mês inválido. Digite um mês entre 1 e 12.\n");
        }
    } while(erro);
    return mes;
}

bool ehBissexto(int ano){
    if(ano % 400 == 0){
        return true;
    } else if(ano % 100 == 0){
        return false;
    } else if(ano % 4 == 0){
        return true;
    } else {
        return false;
    }
}

void qtdDias(int mes, int ano){
    int dias;

    switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            dias = 31;
            break;
        case 4: case 6: case 9: case 11:
            dias = 30;
            break;
        case 2:
            if(ehBissexto(ano)){
                dias = 29;
            } else {
                dias = 28;
            }
            break;
        default:
            printf("Mês inválido!\n");
            return;
    }

    printf("O mês %d tem %d dias.\n", mes, dias);
}

int main(){
    apresentacao();

    int mes = lerMes();
    
    int ano;
    if(mes == 2){
        printf("Qual o ano que quer saber: ");
        scanf("%d", &ano);
    }

    qtdDias(mes, ano);

    return 0;
}