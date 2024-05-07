//Abaixo é apresentada a função de Ackerman, válida para valores inteiros e não negativos de m e n. 
//Para ela, construa uma versão recursiva do algoritmo. Antes da implementação em C, verifique 
//manualmente o seu comportamento para a chamada A(1, 2).
//          {n + 1, para m=0
//A(m, n) = {A(n-1, 1), para m>0 e n=0
//          {A(m-1, A(m, n-1) ), para m>0 e n>0
#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nFuncao de Ackerman\n\n");
}

int leiaM(){
    int a;
    printf("digite o valor de a:");
    scanf("%d", &a);
    return a;
}
int leiaN(){
    int b;
    printf("digite o valor de b:");
    scanf("%d", &b);
    return b;
}

int ackerman(int m, int n){
    int ack = 0;

    if(m == 0){
        ack = n + 1;
    }
    else if(m > 0 && n == 0){
        ack = ackerman(m - 1, 1);
    }
    else if(m > 0 && n > 0){
        ack = ackerman(m - 1, ackerman(m, n -1));
    }

    return ack;
}

int main(){
    apresentacao();

    int m = leiaM();
    int n = leiaN();
    printf("o resultado de A(%d, %d) e:%d", m, n, ackerman(m, n));
    return 0;
}