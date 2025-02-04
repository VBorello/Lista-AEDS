#include <stdio.h>

int main()
{
    printf("\nnNum de Divisores\n");

    int num, divisores = 0;

    printf("Digite o numero que deseja saber a quantidade de divisores:");
    scanf("%d", &num);

    for(int i = 1; i < num; i++){
        if(num % i == 0){
          divisores++;
        }  
    }

    printf("\nO numero %d possui %d divisores", num, divisores);

    return 0;
}
