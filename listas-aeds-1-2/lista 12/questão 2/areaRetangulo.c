#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nCalculadora da area de um retangulo\n\n");
}

void lerAltura(int* h){
    printf("Digite a altura do retangulo: ");
    scanf("%d", h);
}

void lerbase(int* base){
    printf("\nDigite a base do retangulo: ");
    scanf("%d", base);
}

void calcularArea(int h, int base, int* area){
    *area = base * h;
}

void printResultado(){
    int h;
    lerAltura(&h);
    int base;
    lerbase(&base);

    int area;
    calcularArea(h, base, &area);

    printf("\nA area do retangulo e: %d", area);
}

int main(){
    apresentacao();
    printResultado();

    return 0;
}