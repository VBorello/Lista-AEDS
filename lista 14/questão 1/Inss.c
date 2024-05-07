#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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
    float bruto, inss, transporte;

    bruto = LerBruto();
    inss = calcularInss(bruto);
    transporte = calcularTransporte(bruto);

    float salarioLiquido = Liquido(bruto, inss, transporte);

    printf("INSS: %.2f\n", inss);
    printf("Ajuda para transporte: %.2f\n", transporte);
    printf("Salario liquido: %.2f\n", salarioLiquido);

    return 0;

}