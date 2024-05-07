#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nsoma de N ate M recursivo\n\n");
}
int someNM(int n, int m){
    
    if(n > m){
        printf("erro");
        return 0;
    }
    return n + someNM(n +1, m);
}

int leiaN(){
    int n;
    printf("\ndigite o valor de n:");
    scanf("%d", &n);
    return n;
}

int leiaM(){
    int m;
    printf("\ndigite o valor de m:");
    scanf("%d", &m);
    return m;
}

int main(){
    apresentacao();

    int n = leiaN();
    int m = leiaM();

    printf("a soma dos numeros %d ate %d e: %d\n", n, m, someNM(n, m));

    return 0;
}