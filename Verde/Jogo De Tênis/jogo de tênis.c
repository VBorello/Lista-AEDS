#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return abs(a - b);
}

int main() {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);

    // diferença da soma dos niveis
    int diff1 = abs_diff((A + B), (C + D));
    int diff2 = abs_diff((A + C), (B + D));
    int diff3 = abs_diff((A + D), (B + C));

    // menor diferença
    int menor_diff = diff1;
    if (diff2 < menor_diff) {
        menor_diff = diff2;
    }
    if (diff3 < menor_diff) {
        menor_diff = diff3;
    }

    printf("%d\n", menor_diff);

    return 0;
}
