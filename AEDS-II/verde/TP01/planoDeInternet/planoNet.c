#include <stdio.h>
#include <stdlib.h>

void lerPlano(int *plano){
    scanf("%d", plano);
}

void lerMeses(int *meses){
    scanf("%d", meses);
}

void calcularSobra(int plano, int meses){

    int sobra = plano;
    int gasto;
    
    for(int i = 0; i < meses; i++){
        scanf("%d", &gasto);
        sobra += plano - gasto;
    }
    
    printf("%d\n", sobra);
}


int main(){

    int meses;
    lerMeses(&meses);
    int plano;
    lerPlano(&plano);

    calcularSobra(meses, plano);

    return 0;
}