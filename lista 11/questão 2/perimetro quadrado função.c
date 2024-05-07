#include<stdio.h>

void apresentacao(){
    printf("\nCalculador do Perimetro do quadrado\n\n");
}

int leiaLado(){

    int lado;

    printf("Digite o lado do quadrado:");
    scanf("%d", &lado);

return lado;
}

int perimetro(int lado){
    int perimetro = lado * 4;

    return perimetro;
}

int mostraResultado(int resultado){
    printf("O perimetro do quadrado e igual a :%d", resultado);
}

int main (){
    apresentacao();
    int lado = leiaLado();

    int resultado = perimetro(lado);
    mostraResultado(resultado);
}


