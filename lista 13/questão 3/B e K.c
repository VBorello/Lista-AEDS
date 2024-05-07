#include <stdio.h>

void teste(int n, int *b, int *k){
    int i, j;
    *b = 1;

        for(i = 1; i * i <= n; i++){
            if (n % i == 0){
                j = n / i;
            
            if(i <= j && i >= *b){
                *b = i;
                *k = j;
            }
        }
    }
}

int lerNum(){
     int n;
     printf("Digite o valor de n: ");
     scanf("%d", &n);
     return n;
}

int main(){
    int n, b, k;

    n = lerNum();

    teste(n, &b, &k);

    printf("b = %d, k = %d, b * k = %d\n", b, k, b * k);
}