#include <stdio.h>

void apresentacao(){
	printf("\nMaior e Menor entre x numeros\n\n");
}

void encontreMaior(int n){
	
	int num, maior, menor;

	printf("Digite o primeiro numero:");
	scanf("%d", &num);
	
	maior = menor = num;


	for (int i = 2; i <= n; i++){
		printf("digite o %d numero", i);
		scanf("%d", &num);

		if(num > maior){
			maior = num;
		}
		if(num < menor){
			menor = num;
		}
	}

	printf("O maior número digitado é: %d\n", maior);
    	printf("O menor número digitado é: %d\n", menor);
}

	int main(){
	
		int n;

		apresentacao();
	
		printf("digite a quantidade de números:");
		scanf("%d", &n);

		encontreMaior(n);

		return 0;
	}	
