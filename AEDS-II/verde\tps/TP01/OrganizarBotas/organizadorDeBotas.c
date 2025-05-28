#include <stdio.h>
#include <stdlib.h>

int main(){

    int pares = 0;
    int botas;
    int tamanho;
    char lado;

    scanf("%d", &botas);

    //60 tamanho maximo de bota
    int botasD[60] = {0};
    int botasE[60] = {0};

    for(int i = 0; i < botas; i++){
        scanf("%d %c", &tamanho, &lado);
        if(lado == 'D'){
            botasD[tamanho]++;
        }
        else{
            botasE[tamanho]++;
        }
    }

    //30 tamanho minimo de bota
    for(int i = 30; i <= 60; i++){
        if(botasD[i] < botasE[i]){
            pares += botasD[i];
        }
        else{
            pares += botasE[i];
        }
    }

    printf("%d\n", pares);

    return 0;
}