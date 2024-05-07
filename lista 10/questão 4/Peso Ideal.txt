#include <stdio.h>

void apresentar(){
  printf("\nPeso Ideal\n\n");
}

char leiaGenero(){
  char genero;
  printf("Digite o seu genero (F/M):");
  scanf(" %c", &genero);

  return genero;
}
float leiaAltura(){
  float altura;
  printf("\ndigite sua altura:");
  scanf(" %f", &altura);

  return altura;
}

float pesoIdealF(float altura){
  return (62.1 * altura) - 44.7; 
  }
float pesoIdealM(float altura){
  return (72.7 * altura) - 58;
}
float mostrarPesoIdeal(float resultado){
  printf("\nO seu peso ideal é: %.2f", resultado);
}
int main(){
  apresentar();
  char genero = leiaGenero();
  float altura = leiaAltura();
  float resultado;
  
  if(genero == 'M'){
    resultado = pesoIdealM(altura);
  }
  if(genero == 'F'){
    resultado = pesoIdealF(altura);
  }
  else{
    printf("Genero invalido");
    return 1;
  }
  mostrarPesoIdeal(resultado);
  return 0;
}
