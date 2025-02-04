#include <stdio.h>
#include <stdlib.h>

void apresentaco(){
    printf("\nFatorial!!\n\n");
}

int lerNum(){
    int fat;
    printf("Digite o numero que deseja saber el fatorial: ");
    scanf("%d", &fat);
    return fat;
}

int calcularFat(int fat){
    int multiplicacao = 1;
    for(int i = 0; i < fat; i++){
        multiplicacao *= fat;
    }
    return multiplicacao;
}

int main(){
    apresentaco();
    int multiplicacao, fat;
    fat = lerNum();
    multiplicacao = calcularFat(fat);

    printf("%d! e igual a: %d", fat, multiplicacao);

    return 0;
}