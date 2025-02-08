#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nNumeros de Divisores de N\n\n");
}

void lerN(int* n){
    printf("Qual numero deseja saber o numero de divisores? ");
    scanf("%d", n);

}

void identificador(int n, int* divisores){

    *divisores = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            (*divisores)++;
        }
    }
}

int main(){
    apresentacao();

    int n;
    int divisores;
    lerN(&n);

    identificador(n, &divisores);

    printf("\n%d tem %d divisores\n", n, divisores);

    return 0;
}