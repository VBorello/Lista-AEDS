#include <stdio.h>
#include <stdlib.h>

void apresentar(){
  printf("\nDias Vividos\n\n");
}
void lerIdade(int *idade){
    printf("Digite sua idade:");
    scanf(" %d", idade);
}

int CalcularDiasVividos(int idade){
  return idade*365.25;
}
int main(){
  int idade;
  
  apresentar();
  
  lerIdade(&idade);
  int diasVividos = CalcularDiasVividos(idade);

  printf("Dias vividos ate o ultimo aniversario: %d", diasVividos);
  
  return 0;
}