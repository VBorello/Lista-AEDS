#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void apresentacao(){
    printf("\nCalcular salario Bruto(Liquido - INSS - Transporte)\n\n");
}
float LerBruto(){
    float salario;
    printf("Informe o Valor do Salario(liquido):");
    scanf("%f", &salario);
    return salario;
}
float calcularInss(float bruto){
    return bruto * 9 / 100;
}
float calcularTransporte(float bruto){
    return bruto * 6 / 100;
}

float Liquido(float bruto, float inss, float transporte){
    return bruto + transporte - inss;
}
int main(){

    apresentacao();

    float bruto, inss, transporte;

    bruto = LerBruto();
    inss = calcularInss(bruto);
    transporte = calcularTransporte(bruto);

    float salarioBruto = Liquido(bruto, inss, transporte);

    printf("INSS: %.2f\n", inss);
    printf("Ajuda para transporte: %.2f\n", transporte);
    printf("Salario Bruto: %.2f\n", salarioBruto);

    return 0;

}