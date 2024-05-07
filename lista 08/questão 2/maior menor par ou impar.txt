#include <stdio.h>
#include <stdbool.h>

int main() 
{
  printf("\n>Maior >Menor\n\n");

  char continuar;
  continuar = 's';
  
  do {

    int n, valor, menor_par = 0, maior_par = 0, menor_impar = 0, maior_impar = 0, par = 0, impar = 0;
    int primeiro = 1;
    bool erro;
    
    printf("quantos valores quer?:");
    scanf(" %d", &n);

    for (int i = 0; i < n; i++) {
      
      printf("\ndigite um valor:");
      scanf(" %d", &valor);
      
        if(valor % 2 == 0){
          par++;
          if (primeiro || valor > maior_par)
                maior_par = valor;
          if (primeiro || menor_par == 0 || valor < menor_par)
                menor_par = valor;
        } else {
            impar++;
            if (primeiro || valor > maior_impar)
                maior_impar = valor;
            if (primeiro || menor_impar == 0 || valor < menor_impar)
                menor_impar = valor; 
          }   
      
      primeiro = 0;
      
    }
    printf("são %d numeros pares e %d numeros impares", par, impar);
    printf("\no maior impar e:%d\n", maior_impar);
    printf("o menor impar e:%d\n", menor_impar);
    printf("o maior par e:%d\n", maior_par);
    printf("o menor par e:%d\n", menor_par);
    
    printf("\nDeseja continuar (s/n):");
    scanf(" %c", &continuar);
  } while (continuar == 's' || continuar == 'S');
    
  return 0;
  
}