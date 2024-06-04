// cada vêz que n repetir no for o denominador e o nominador trocão e decrementa -1 do denominador e acrescenta +1 do nominador
#include <stdio.h>

int main(void) {
  printf("\nsequencia (10/100 , 99/11)\n\n");

  int n, numerador = 10, denominador = 100;

  printf("\nquantos termos da sequência?:");
  scanf(" %d", &n);
  
  for(int i = 0; i < n; i++){
    if ( i % 2 == 0) {
       numerador++;
       denominador--;
       printf("O %d termo da sequencia e: %d/%d\n", i + 1, numerador, denominador);
    }   else {
          numerador++;
          denominador--;
          printf("O %d termo da sequencia e: %d/%d\n", i + 1, denominador, numerador);
        }
  }
  return 0;
}
