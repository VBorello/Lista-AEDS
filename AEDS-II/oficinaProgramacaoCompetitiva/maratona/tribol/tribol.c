#include <stdio.h>

int main() {

    int testes; 
    scanf("%d", &testes);

    while (testes--) {
        int p;
        scanf("%d", &p);

        int green = 0, red = 0, blue = 0;
        char time, marcou;

        for (int i = 0; i < p; i++) {
            scanf(" %c %c", &time, &marcou);

            if (time == 'R' && marcou == 'G') {
                red += 2;
            } else if (time == 'R' && marcou == 'B') {
                red += 1;
            }

            if (time == 'G' && marcou == 'B') {
                green += 2;
            } else if (time == 'G' && marcou == 'R') {
                green += 1;
            }

            if (time == 'B' && marcou == 'R') {
                blue += 2;
            } else if (time == 'B' && marcou == 'G') {
                blue += 1;
            }
        }

        if (red == blue && blue == green) {
            printf("trempate\n");
        } else if (red > blue && red > green) {
            printf("red\n");
        } else if (blue > red && blue > green) {
            printf("blue\n");
        } else if (green > blue && green > red) {
            printf("green\n");
        } else if (red > blue && red == green) {
            printf("empate\n");
        } else if (green > red && green == blue) {
            printf("empate\n");
        } else if (blue > red && blue == green) {
            printf("empate\n");
        }
    }

    return 0;
}