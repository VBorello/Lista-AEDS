#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nTroca Primeiro termo do array pelo ultimo.\n\n");
}
int lerTamanho(){
    int tamanho;
    prtinf("digite o tamanho do array:");
    scanf("%d", &tamanho);
    return tamanho;
}

void lerArranjo(int v[], int tamaho){
    for(int i = 0; i < tamaho; i++){
        printf("Digite o %d termo:", i + 1);
        scanf("%d", &v[i]);
    } 
}

void trocaPrimeiroPorUltimo(int v[], int tamanho){
    if(tamanho > 1){
        int aux = v[0];
        v[0] = v[tamanho - 1];
        v[tamanho - 1] = aux;
    }
}

int main(){








    return 0;
}
