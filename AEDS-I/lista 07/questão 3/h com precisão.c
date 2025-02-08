//Calcular e escrever o valor de H, sendo H igual a:
//H = 1/1 + 1/3 + 1/9 + 1/27 + ...
//H com precisão de N termos, sendo N um valor lido.
//Obs: não se esqueça que o operador de divisão em C é sobrecarregado: divisão inteira e divisão real – a
//operação é definida em termos do tipo dos operandos.

#include <stdio.h>
#include <stdbool.h>

int main() 
{
  printf("\nValor de H com precisão\n\n");

  int n;
  float h = 0;
  bool erro;

  do {
       printf("\nInforme o numero de valores:");
       scanf(" %d", &n);
       erro = n <= 0;
       if(erro) {
      printf("valor invalido"); }
     } while (erro);

      
  for (int i = 0; i < n; i++) {
  h += 1/(i * 3);
  }   
  printf("O valor com precisão de H com: %d termos e:%.6lf\n", n, h);

  return 0;

} 
