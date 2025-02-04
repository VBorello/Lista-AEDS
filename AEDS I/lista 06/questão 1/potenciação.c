#include <stdio.h>

    int main() 
{
  printf("\ncalculo de potenciação\n\n");
  
  int expoente;
  float base, potenciação = 1;
  
  printf("digite a base:");
  scanf(" %f", &base);
  printf("digite o expoente");
  scanf(" %d", &expoente);
  
  for (int i = 0; i < expoente; i++)
  {
  potenciação = potenciação * base;
  }
  printf("\n %.2f ^ %i :%.2f", base, expoente, potenciação );

  return 0;
      
}
