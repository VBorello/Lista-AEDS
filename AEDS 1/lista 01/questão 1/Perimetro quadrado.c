#include <stdio.h>

int main(){

printf("\nPerimetro de um Quadrado\n\n");


	int lado, soma;

	printf("digite o lado do quadrado:");
	scanf("%d", &lado);

	soma = lado * 4;

	printf("O perimetro do quadrado e: %d", soma);

return 0;
}