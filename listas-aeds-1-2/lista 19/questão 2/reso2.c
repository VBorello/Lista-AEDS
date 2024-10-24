#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
	printf("\nPrimo Antecessor e Sucessor de X\n\n");
}

void lerx(int *x){
	printf("Digite o valor de x: ");
	scanf("%d", x);
}

bool esPrimo(int n){
	bool primo = true;
	
	if(n <= 1){
		primo = false;
	}
	
	for(int i = 2; i < n; i++){
		if(n % i == 0){
			primo = false;
		}
	}
	
	return primo;
}

void calcularPrimoAntecessor(int x, int *antecessor){
	int i = x - 1;
	while(*antecessor == 0 && i > 1){
		if(esPrimo(i)){
			*antecessor = i;
		}
		i--;
	}
	printf("\nO primo antecessor a %d é: %d", x, *antecessor);
}

void calcularPrimoSucessor(int x, int *sucessor){
	int i = x + 1;
	while(*sucessor == 0){
		if(esPrimo(i)){
			*sucessor = i;
		}
		i++;
	}

	printf("\nO primo sucessor a %d é: %d", x, *sucessor);
}

int main(){
	apresentacao();
	
	int x;
	lerx(&x);
	
	int antecessor = 0;
	int sucessor = 0;
	
	calcularPrimoAntecessor(x, &antecessor);
	calcularPrimoSucessor(x, &sucessor);

	return 0;
}