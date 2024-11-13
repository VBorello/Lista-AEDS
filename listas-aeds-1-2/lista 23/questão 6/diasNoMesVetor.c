# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    system("clear");
    printf("\nDias do Mes Vetor\n\n");
}

void lerMes(int* mes){
     do {
        printf("Digite o mês (1 a 12): ");
        scanf("%d", mes);
        if (*mes < 1 || *mes > 12) {
            printf("Mês inválido. Tente novamente.\n");
        }
    } while (*mes < 1 || *mes > 12);
}

bool ehBissexto(int ano){

    int bissexto = false;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true; 
    }
    return bissexto;
}


void verDias(int mes){
    
    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    

    switch (mes) {
        case 1:
            printf("Janeiro tem %d dias.\n", meses[0]);
            break;
        case 2:
            int ano;
            printf("Digite um ano: ");
            scanf("%d", &ano);
            
            if (ehBissexto(ano)) {
                meses[1] = 29;
            }
            printf("Fevereiro tem %d dias.\n", meses[1]);

            break;
        case 3:
            printf("Março tem %d dias.\n", meses[2]);
            break;
        case 4:
            printf("Abril tem %d dias.\n", meses[3]);
            break;
        case 5:
            printf("Maio tem %d dias.\n", meses[4]);
            break;
        case 6:
            printf("Junho tem %d dias.\n", meses[5]);
            break;
        case 7:
            printf("Julho tem %d dias.\n", meses[6]);
            break;
        case 8:
            printf("Agosto tem %d dias.\n", meses[7]);
            break;
        case 9:
            printf("Setembro tem %d dias.\n", meses[8]);
            break;
        case 10:
            printf("Outubro tem %d dias.\n", meses[9]);
            break;
        case 11:
            printf("Novembro tem %d dias.\n", meses[10]);
            break;
        case 12:
            printf("Dezembro tem %d dias.\n", meses[11]);
            break;
        default:
            printf("Mês inválido.\n");
            break;
    }
}

int main(){
    apresentacao();

    int mes;
    lerMes(&mes);
    verDias(mes);

    return 0;
}