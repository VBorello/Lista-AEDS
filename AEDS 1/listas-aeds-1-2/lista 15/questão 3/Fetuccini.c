#include <stdio.h>

void apresentacao(){
    printf("\nSequencia de Fetuccini.\n");
}


void fetucciniSequence(int n, int t0, int t1) {
    int atual, anterior1 = t1, anterior2 = t0; 

    printf("%d ", t0);
    if (n > 1) {
        printf("%d ", t1); 
    }

    for (int i = 2; i < n; i++) {
        if (i % 2 == 0) {
            atual = anterior1 + anterior2; 
        } else {
            atual = anterior1 - anterior2; 
        }

        printf("%d ", atual); 

        anterior2 = anterior1;
        anterior1 = atual;
    }

    printf("\n");
}

int main() {

    apresentacao();
    
    int n;
    int t0 = 1;  
    int t1 = 1;  

    printf("Digite o número de termos da sequência: ");
    scanf("%d", &n);

    fetucciniSequence(n, t0, t1);

    return 0;
}
