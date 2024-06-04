#include <stdio.h>

int main() 
{
  printf("\nMaior e Menor entre X valores\n");

  int valor, maior, menor;
  float repetição;
  
  printf("\nquantos valores quer comparar?:");
  scanf(" %f", &repetição);

  printf("\nDigite um valor:");
  scanf(" %d", &valor);
  maior = menor = valor;
  
  for(int i = 1; i < repetição; i++)
  {

    printf("\nDigite um valor:");
    scanf(" %d", &valor);
   
    if (valor > maior) {
      maior = valor;
    }
    else if (valor < menor) {
      menor = valor;
    }
  }
  printf("\nO maior valor e: %d e o menor e:%d", maior, menor);
  return 0;
}