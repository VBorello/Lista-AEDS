#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nArvore pela Metade\n\n");
}

void lerN(int* n){
    printf("Digite o número de linhas da árvore: ");
    scanf("%d", n);
}

void imprimirArvore(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
            for(int folhas = 1; folhas <= i; folhas++) {
                printf("*");
            }
        printf("\n");
    }
}

int main() {
    apresentacao();
    
    int linhas;
    lerN(&linhas);

    

    imprimirArvore(linhas);

    return 0;
}
