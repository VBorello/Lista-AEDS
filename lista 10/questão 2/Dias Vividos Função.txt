#include <stdio.h>
#include <stdlib.h>

void apresentar(){
  printf("\nDias Vividos\n\n");
}
int lerIdade(){
  int idade;
    printf("Digite sua idade:");
    scanf(" %d", &idade);
  return idade;
}

int diasVividos(int idade){
  return idade*365.25;
}
int mostrarDias(int dias){
  printf("você ja viveu: %d dias", dias);
}
int main(){

  apresentar();
  
  int idade = lerIdade();

  int dias = diasVividos(idade);
  mostrarDias(dias);
  
  return 0;
}