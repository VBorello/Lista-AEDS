#include <stdio.h>
#include <stdlib.h>

int main(){

    int qtd = 0;
    int n;
    int par = 0, impar = 0;
    printf("quantos numeros quer saber? ");
    scanf("%d", &qtd);

    for(int i = 0; i < qtd; i++){
        printf("\ndigite o %d num:", i + 1);
        scanf("%d", &n);
        if(n % 2 == 0){
            par++;
        }
        else{
            impar++;
        }
    }

    printf("\n%d são impares e %d são pares.", impar, par); 

    return 0;

}