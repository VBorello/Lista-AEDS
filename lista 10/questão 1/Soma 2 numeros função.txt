#include <stdio.h>
#include <stdlib.h>

void apresentar(){
  printf("\nsoma de 2 numeros função\n\n");
}
float lerNumero(){
  float num;
  printf("\ndigite um numero:");
  scanf(" %f", &num);
  return num;
}
float soma(float num1, float num2){
  return num1 + num2;
}
float MostrarResultado(float resultado){
  printf("O resultado da soma é: %.2f\n", resultado);
}

int main(){
  apresentar();
  float num1 = lerNumero();
  float num2 = lerNumero();

  float resultado = soma(num1, num2);
  MostrarResultado(resultado);

  return 0;
}