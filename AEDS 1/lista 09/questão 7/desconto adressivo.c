#include <stdio.h>

int main() {
  printf("\nTabela de Descontos\n\n");

  float desconto, preco;

  printf("digite o preço do produto:");
  scanf(" %f", &preco);

  while(preco != 0){
    if(preco < 500){
      desconto = preco * 70/100;
    }
    if(preco >= 500 && preco <= 3000){
      desconto = preco * 60/100;
    }
    if(preco > 3000){
      desconto = preco * 50/100;
    }
     
      printf("O desconto do seu produto sera de: %.2f\n", desconto); 
    
      printf("digite o preço do produto(0 para encerra):");
      scanf(" %f", &preco);
    
    
  }  
  
  return 0;
}