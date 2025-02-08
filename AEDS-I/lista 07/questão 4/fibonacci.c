#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("\nSerie de Fibonacci\n");
  
    char continuar;
    continuar = 's';

    while(continuar == 'S' || continuar == 's') 
    {
      int t, resultado, n;
      bool erro;

      do {
        printf("\nInsira o valor do primeito termo:");
        scanf(" %d", &t);
        erro = t <= 0 ;
        if (erro) {
          printf ("valor invalido");
        }
      } while (erro);

      int b = t + 1;
      
      do {
        printf("\nInsira o numero de termos:");
        scanf(" %d", &n);
        erro = n <= 0 ;
        if (erro) {
          printf ("valor invalido");
        }
      } while (erro);

      for(int i = 1; i <= n; i++)
    {
        printf(" %d", t);
        resultado = t + b;
        t = b;
        b = resultado;
      }
        printf("\n\nDeseja ver mais termos(S/N):");
        scanf(" %c", &continuar);
  }
  
    printf("\ntchal!");
  
    return 0;
}  