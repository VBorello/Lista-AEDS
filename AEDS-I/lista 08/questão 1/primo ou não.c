#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("\nPrimo ou não\n\n");

    int n, i = 2;
    bool primo = true;
    
    do { 
      printf("qual o numero quer saber se é ou não primo?:");
      scanf(" %d", &n);
    } while (n < 2);

      while(primo && i <= n/2){
      if(n % i == 0 ) {
        primo = false;
      }
      i++;
      } 
      if(primo){
        printf("é primo");
      } else {
        printf("não é primo");
      }
  
  return 0;
  
}

//declare x
//int soma, x, media
//printf scanf x
//flag enquanto while (x != 0){
//
//} fim do enquanto
