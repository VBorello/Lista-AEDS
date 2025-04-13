#include <stdio.h>
#include <math.h>

int main() {
    double f;

    const double diferenca = (sqrt(25 + 10 * sqrt(5)) - 5) / 10;

    while (scanf("%lf", &f) != EOF) {

        double lado = f * diferenca;

        printf("%.10lf\n", lado);
    }

    return 0;
}