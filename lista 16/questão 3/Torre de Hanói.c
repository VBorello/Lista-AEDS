#include <stdio.h>
#include <stdlib.h>

void TorreDeHanoi(int n ,char posicao1, char proxposicao, char aux){
    if(n == 1){
        printf("Mova o disco 1 de %c para %c\n", posicao1, proxposicao);
        return;
    }
    TorreDeHanoi(n - 1, posicao1, aux, proxposicao);
    printf("Mova o disco %d de %c para %c\n", n, posicao1, proxposicao);
    TorreDeHanoi(n - 1, aux, proxposicao, posicao1);
}
int numDisc(){
    int numDisc;
    printf("Quantos discos a torre possui:");
    scanf("%d", &numDisc);
    return numDisc;
}

int main(){
    int discos = numDisc();

    TorreDeHanoi(discos, 'A', 'C', 'B');
    return 0;
}