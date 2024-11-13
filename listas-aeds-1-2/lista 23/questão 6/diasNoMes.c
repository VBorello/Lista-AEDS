#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nDis contidos no mes de sua escolha\n\n");
}

void escolherMes(int* mes){
    printf("Digite qual mês deseja saber a quantidade de dias(1 - 12): ");
    scanf("%d", mes);
}

void escolherAno(int* ano){
    printf("Digite um ano: ");
    scanf("%d", ano);
}

bool ehBissexto(int ano){

    int bissexto = false;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true; 
    }
    return bissexto;
}

void meses(int mes){
    
    int ano;
    escolherAno(&ano);

    switch (mes)
    {
    case 1:{
        printf("janeiro tem: 31 dias");
        
        break;
    }
    case 2:{
        if(ehBissexto(ano)){
            printf("\ncomo %d e bissexto fevereiro tem: 29 dias", ano);
        }
        else{
            printf("\ncomo %d não e bissexto fevereiro tem: 28 dias", ano);
        }
        break;
    }
    case 3:{
        printf("janeiro tem: 31 dias");

        break;
    }
    case 4:{
        printf("janeiro tem: 30 dias");

        break;
    }
    case 5:{
        printf("janeiro tem: 31 dias");

        break;
    }
    case 6:{
        printf("janeiro tem: 30 dias");
        break;
    }
    case 7:{
        printf("janeiro tem: 31 dias");

        break;
    }
    case 8:{
        printf("janeiro tem: 31 dias");

        break;
    }
    case 9:{
        printf("janeiro tem: 30 dias");

        break;
    }
    case 10:{
        printf("janeiro tem: 31 dias");

        break;
    }
    case 11:{
        printf("janeiro tem: 30 dias");

        break;
    }
    case 12:{
        printf("janeiro tem: 31 dias");

        break;
    }

    default:
        break;
    }
}

int main(){
    apresentacao();

    int mes;

    escolherMes(&mes);

    meses(mes);

    return 0;
}