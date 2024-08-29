#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
	printf("\nPrimo ou não\n\n");
}

void lerN(int* n){
	printf("qual numero deseja saber se é primo? ");
	scanf("%d", n);

}

int primoOuN(int n){

	if(n <= 0){
		return 0;
	}
	
	for(int i = 2; i * i<= n; i++){
		if(n % i == 0){
            return 0;
        }
	}
	
	return 1;
}

int main(){
	apresentacao();
	int num;
	lerN(&num);
	
	if(primoOuN(num)){
		printf("\n%d é primo sim", num);
	}
	else{
		printf("\n%d é primo não", num);
	}
	
	return 0;

}
