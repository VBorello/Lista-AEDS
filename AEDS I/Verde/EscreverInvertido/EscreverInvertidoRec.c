#include <stdio.h>

int inverterNumeroRecursivo(int x, int invertido) {
    
    if (x == 0) {
        return invertido;
    }

    return inverterNumeroRecursivo(x / 10, invertido * 10 + (x % 10));
}

int main() {

    int x = 12345;
    int xInvertido = inverterNumeroRecursivo(x, 0);
    
    return 0;
}
