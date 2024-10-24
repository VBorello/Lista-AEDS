#include <stdio.h>

void teste(int n, int *b, int *k) {
    *b = n;
    *k = 1;  
    
    for (int base = 2; base <= n; base++) {
        int potencia = base;
        int exp = 1;
        
        while (potencia < n) {
            potencia *= base;
            exp++;
        }
        
        if (potencia == n) {
            *b = base;
            *k = exp;
            break;
        }
    }
}

int main() {
    int n, b, k;
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    teste(n, &b, &k);
    
    printf("b: %d, k: %d\n", b, k);
    
    return 0;
}
