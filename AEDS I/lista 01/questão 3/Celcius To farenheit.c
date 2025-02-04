#include <stdio.h>
#include <stdlib.h>

int main()
{
    float celcius, farenheit;
    char continuar;

    do{
    printf("\n conversor celcius to farenheit\n");
    printf("\n Digite a temperatura desejada em graus celcius:");
    if (scanf(" %f",&celcius) !=1) {
    printf("Entrada invalida. Por favor, inaira um numero valido.\n");
    while (getchar() !='\n');
    }

    farenheit = celcius * 1.8 + 32;

    printf("\n sua temperatura em farenheit e:%.2f",farenheit);

    printf("\nDeseja converter outra temperatura? (S/N): ");
        scanf(" %c", &continuar);

    } while (continuar == 'S' || continuar == 's');

    printf("\nObrigado por usar o conversor de temperatura!\n");

    return (0);
}
