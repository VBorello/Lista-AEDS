#include <stdbool.h>
#include <stdio.h>

int main() {
  int total = 0, num, par = 0;
  int flag = 0;
  printf("\nPares entre 1000 e 10000\n\n");

  while (!flag){
    printf("digite numeros ente 1000 e 10000 e digite 0 para finalizar:");
    scanf(" %d", &num);

    if(num == 0){
      flag = 1;
    }
    else if (num >= 1000 && num <= 10000){
      total++;
    }
    if(num % 2 == 0){
      par++;  
    }
    else{
      printf("valor invalido");  
    }
  }

  if (total > 0){
    float percentualpar = (float)par / total * 100;
    printf("o percentual de numeros pares e: %.2f%%", percentualpar);
  }
  else{
    printf("nenhum valor foi digitado");
  }
  return 0;
}

// #include <stdio.h>
// #include<stdbool.h>
// #define flag 0

// int main() {
//   printf("\nPares 1000 a 10000\n\n");

//   int n, total = 0, c = 0;
//   bool erro;

//   do{
//     printf("\ndigite qual valor quer:");
//     scanf(" %d", &n);
//     erro = n < 1;
//     if (!erro) {
//       total++;
//       if ((n % 2 == 0) && (n > 1000 && n <= 10000)){
//         c++;
//       }
//     }else if(erro&&n!=0){
//       printf(" invalido\n");
//     }

//   }while (n!=flag);

//     if (total > 0){
//       float percentpares = (float)c / total * 100;
//       printf("%.2f%% pares 1000 a 10000", percentpares);
//     }

//   return 0;
// }