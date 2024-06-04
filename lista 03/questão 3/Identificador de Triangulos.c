
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
  printf("Identificador de triângulos\n\n");

  float a, b, c;
  char continuar;
  continuar = 's';
    
  while (continuar == 's' || continuar == 'S'){
    
  printf("digite o lado 1:");
  scanf("%f", &a);
  printf("digite o lado 2:");
  scanf("%f", &b);
  printf("digite o lado 3:");
  scanf("%f", &c);

  bool triangulo; 
  
  triangulo = false;

  if (a+b > c && a+c > b && b+c > a) 
    triangulo = true;
  if (!triangulo)
  {
    printf("Não e um triangulo");
  }
  else{
    if (a == b && b == c)
      printf("triangulo equilatero");
    else if (a == b || b == c || a == c)
      printf("triangulo isoceles");
    else
      printf("triangulo escaleno");
  }
   printf("\nDeseja continuar? (S/N)");
   scanf(" %c", &continuar);
  
 }
  return 0;
}
