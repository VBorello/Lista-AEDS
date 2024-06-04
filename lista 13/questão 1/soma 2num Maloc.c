#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("soma alocada");
}

int* lerNum(){
    int* num = (int*)malloc(sizeof(int));
    printf("digite um numero:");
    scanf("%d", num);
    return num;
}
int* somar(int* num1, int* num2){
    int* resultado = (int*)malloc(sizeof(int));
    *resultado = *num1 + *num2;
    return resultado;
}
void liberarMemoria(int* numero){
    free(numero);
}

int main(){

    apresentacao();

    int* num1 = lerNum();
    int* num2 = lerNum();

    int* resultado = somar(num1, num2);

    printf("A soma dos numeros e: %d\n", *resultado);

    liberarMemoria(num1);
    liberarMemoria(num2);
    liberarMemoria(resultado);

    return 0;
}
