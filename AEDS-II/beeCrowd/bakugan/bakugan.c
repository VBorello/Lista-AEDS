#include <stdio.h>

void processaJogo(int R, int mark[], int leti[]) {
    int pontosMark = 0, pontosLeti = 0;
    int totalMark = 1, totalLeti = 1;
    
    for (int i = 0; i < R; i++) {
        pontosMark += mark[i];
        pontosLeti += leti[i];
        
        if (i > 0) {
            if (mark[i] == mark[i - 1]) {
                totalMark++;
            } else {
                totalMark = 1;
            }
            
            if (leti[i] == leti[i - 1]) {
                totalLeti++;
            } else {
                totalLeti = 1;
            }
        }
        
        if (totalMark == 3 && totalLeti == 3) {
            totalMark = totalLeti = 0;
        } else if (totalMark == 3) {
            pontosMark += 30;
            totalMark = 0;
        } else if (totalLeti == 3) {
            pontosLeti += 30;
            totalLeti = 0;
        }
    }
    
    if (pontosMark > pontosLeti) {
        printf("M\n");
    } else if (pontosLeti > pontosMark) {
        printf("L\n");
    } else {
        printf("T\n");
    }
}

int main() {
    int R;
    while (scanf("%d", &R) && R != 0) {
        int mark[R], leti[R];
        for (int i = 0; i < R; i++) {
            scanf("%d", &mark[i]);
        }
        for (int i = 0; i < R; i++) {
            scanf("%d", &leti[i]);
        }
        processaJogo(R, mark, leti);
    }
    return 0;
}
