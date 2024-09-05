#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nBissexto ou não\n\n");
}

void lerAno(int* ano){
    
    printf("Qual ano:");
    scanf("%d", ano);
}

bool verSeEBissexto(int ano){
    
    if ((ano % 4 == 0 && ano % 100 != 0) || ( ano % 400 == 0)) {
        printf("\no ano e bissexto");
        return true;
    }
    printf("\no ano não e bissexto");
    return false;
}

char repetir(){
    
    char continua;
    bool erro;

    do{
        printf("\n\ndeseja saber de outro ano?(s/n)");
        scanf(" %c", &continua);

        erro = (continua != 's' && continua != 'S' && continua != 'n' && continua != 'N');

        if(erro){
            printf("\nopcao inválida");
        }
    }while(erro);

    return continua;
}

int main(){
    
    apresentacao();
    char continuar;
    int ano;
    

    do{
        lerAno(&ano);
        verSeEBissexto(ano);

        continuar = repetir();
    }while(continuar == 's' || continuar == 'S');
    
    return 0;
}