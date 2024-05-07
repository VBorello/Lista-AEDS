#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main (){

  printf("\nSalario Minimo\n\n");

  bool erro;
  int n, num_salario_minimo = 0;
  float salario_minimo, salario;
  float menor_salario = 0, maior_salario = 0;
  do{
    printf("digite a quantidade de funcionarios:");
    scanf(" %d", &n);
    erro = n < 1;
    if (erro){
      printf("valor invalido");
    }
  }while (erro);
   do{ 
    printf("digite o valor do salario minimo:");
    scanf(" %f", &salario_minimo);
    erro = salario_minimo <= 0;
    if(erro){
       printf("salario invalido");
    }
  }while (erro);
  
  for(int i = 1; i <= n; i++){
    printf("digite o salario");
    scanf(" %f", &salario);
  
    if (salario > maior_salario){
       maior_salario = salario;
     }
     if(salario > menor_salario && i == 1){
       menor_salario = salario;
     }
    if (salario < menor_salario){
      menor_salario = salario;
    }
    
     if(salario == salario_minimo){
       num_salario_minimo++;
     }  
  }
  
  float media =((float) num_salario_minimo / (float) n) * 100;
  float amplitude = maior_salario - menor_salario;
  
  printf("maior salario: %.2f\n", maior_salario);
  printf("menor salario: %.2f\n", menor_salario);
  printf("a amplitude salarial e de: %.2f\n", amplitude);
  printf("funcionarios que recebem um salario minimo: %d\n", num_salario_minimo);
  printf("media de funcionarios que recebem um salario minimo: %.2f\n", media);

  return 0;
}