#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long somaDigitos(long long n){
    
    if(n == 0){
        return 0;
    }

    return (n % 10) + somaDigitos(n / 10);
}

int main(){

    long long n;
    while(scanf("%lld", &n) == 1){
        printf("%lld\n", somaDigitos(n));
    }

    return 0;
}