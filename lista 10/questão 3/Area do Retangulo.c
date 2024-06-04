#include <stdio.h>
#include <stdbool.h>



void apresenta(){
  printf("\nArea de um retangulo\n\n");
}
float lerBase(){
  float num;
  bool erro = num < 0;
  do{
    printf("\ndigite a base:");
    scanf(" %f", &num);
    if(erro){
      printf("valor invalido");
    }
  }while (erro);

  return num;
}
float lerAltura(){
  float num;
  bool erro = num < 0;
  do{
    printf("\ndigite a altura:");
    scanf(" %f", &num);
    if(erro){
      printf("valor invalido");
    }
  }while (erro);
  return num;
}
float area(float base, float altura){
  return base * altura;
}
float mostrarArea(float resultado){
  printf("a area desse retângulo é de:%.2f", resultado);
}
int main (){
  apresenta();
  float base = lerBase();
  float altura = lerAltura();

  float resultado = area(base, altura);
  mostrarArea(resultado);

  return 0;
}