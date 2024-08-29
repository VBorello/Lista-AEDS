#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nN termos de H\n\n");
}

void lerTermos(int* termos){
    
    printf("quantos termos de H quer? ");
    scanf("%d", termos);
}

void calcularH(int termos){
    
    int h = 1;
    int denominadorH = 1;
    for(int i = 0; i < termos; i++){
        if(i < 1){
            denominadorH = 1;
        }
        else{
            denominadorH *= 3;
        }

        printf("%d/%d ", h, denominadorH);
    }
}

int main(){
    apresentacao();

    int termos;
    lerTermos(&termos);

    calcularH(termos);

    return 0;
}