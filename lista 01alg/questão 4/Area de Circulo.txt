#include <stdio.h>

int main()
{
    printf("\ncalculador de area circular\n\n");

    float area, raio;
    char continuar;
    continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
      {  
    printf("informe o raio do seu circulo:");
    scanf(" %f",&raio);

    area=3.14*raio*raio;

    printf("a area do seu circulo e:%.2f",area);
      } 
    printf("\n\nDeseja continuar (s/n):");
    scanf(" %c", &continuar);
    }  
      
}