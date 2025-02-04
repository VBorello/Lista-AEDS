#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nFatorial Recursivo\n\n");
}

int leiaNum(){
    int n;
    printf("Digite o numero do fatorial:");
    scanf("%d", &n);
    return n;
}

int fat(int n){
    if (n == 0){
        return 1;
    }
    return n * fat(n - 1);
}

int main(){
    apresentacao();
    int n = leiaNum();

    printf("o fatorial de %d e:%d", n, fat(n));

    return 0;
}
