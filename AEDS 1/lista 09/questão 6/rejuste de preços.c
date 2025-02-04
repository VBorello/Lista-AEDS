#include <stdio.h>
#include <stdbool.h>

int main() {
  printf("\nPolitica de Preços\n\n");

  int produtos;
  float preco, maior_preco = 0, maior_preco2 = 0;
  bool erro;

  do{
    printf("Quantos produtos deseja reavaliar:");
    scanf(" %d", &produtos);
    erro = produtos <= 0;
    if(erro){
      printf("valor invalido\n");
    }
  }while (erro);
    
  for(int i = 0; i < produtos;i++){
    
    do{
    printf("valor do produto:");
    scanf(" %f", &preco);
    erro = produtos <= 0;
      if(erro){
        printf("valor invalido\n");
      }
    }while (erro);
  
    if(preco < 2000 > maior_preco){
       maior_preco = preco;
    }
    if(preco > 2000){
      maior_preco2 = preco;
    }
  }

  printf("o maior preco ate 2000 e: %.2f\n", maior_preco);
  printf("o maior preco apos 2000 e: %.2f\n", maior_preco2);
  
  return 0;
}