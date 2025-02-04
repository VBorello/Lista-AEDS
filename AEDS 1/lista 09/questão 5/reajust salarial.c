#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("\nReajuste salarial\n\n");
  
  int qtsalarios;
  float salario, reajuste, acrescimo;
  bool erro;

  do{
  printf("quantos salarios deseja saber o reajuste:");
  scanf(" %d", &qtsalarios);
    erro = qtsalarios <= 0;
      if(erro){
        printf("\nvalor invalido\n");
      }
    }while (erro);

    
  for(; qtsalarios > 0; qtsalarios--){ //enquanto qtsalario for maior que 0 repete, e diminui
    do{
      printf("\nqual o valor do salario:");
      scanf(" %f", &salario);
      erro = salario <= 0;
      if(erro){
        printf("\nvalor invalido\n");
      }
    }while (erro);
      
    if(salario < 1000){
      reajuste = salario * 10 / 100;
      acrescimo = reajuste + salario;
      printf("o reajuste salarial e de 10%% e no total sera: %.2f\n", acrescimo);
    }
    else if(salario >= 100 && salario <= 2000){
      reajuste = salario * 8 / 100;
      acrescimo = reajuste + salario;
      printf("o reajuste salarial e de 8%% e no total sera: %.2f\n", acrescimo);
    }
    else {
      reajuste = salario * 7 / 100;
      acrescimo = reajuste + salario;
      printf("o reajuste salarial e de 7%% e no total sera: %.2f\n", acrescimo);
    }
  
  } 
  
  return 0;
}



// #include <stdio.h>

// int main() {
//   printf("\nReajuste salarial\n\n");

//   int qtsalarios;
//   float salario, reajuste, acrescimo;

//   printf("quantos salarios deseja saber o reajuste:");
//   scanf(" %d", &qtsalarios);

//   for(int i = 0; i < qtsalarios; i++){

//     printf("qual o valor do salario");
//     scanf(" %f", &salario);

//     if(salario < 1000){
//       reajuste = salario * 10 / 100;
//       acrescimo = reajuste + salario;
//     }
//     else if(salario >= 100 && salario <= 2000){
//       reajuste = salario * 8 / 100;
//       acrescimo = reajuste + salario;
//     }
//     else {
//       reajuste = salario * 7 / 100;
//       acrescimo = reajuste + salario;
//     }
//     printf("o reajuste salarial e de: %.2f e no total sera: %.2f", reajuste, acrescimo);

//   } 

//   return 0;
// }