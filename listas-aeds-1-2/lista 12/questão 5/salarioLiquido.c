#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nCalculador de Salario liquido\n\n");
}

void lerValorHora(float *valorHora){
    printf("Digite o valor da hora trabalhada: ");
    scanf("%f", valorHora);
}

void lerHoras(float *horas){
    printf("\nDigite quantas horas são trabalhadas: ");
    scanf("%f", horas);
}

void calcularBruto(float valorHora, float horas, float* bruto){
    *bruto = valorHora * horas;
}

void calcularInss(float bruto, float* inss){
    *inss = bruto / 100 * 9;
}

void calcularLeao(float bruto, float* leao){
    *leao = bruto / 100 * 10;
}

void calcularLiquido(float leao, float bruto, float inss, float* liquido){
    *liquido = bruto - leao - inss;
} 

void tudo(){
    float valorHora;
    lerValorHora(&valorHora);
    float horas;
    lerHoras(&horas);
    float bruto;
    calcularBruto(valorHora, horas, &bruto);

    float inss;
    calcularInss(bruto, &inss);
    float leao;
    calcularLeao(bruto, &leao);
    float liquido;
    calcularLiquido(leao, bruto, inss, &liquido);

    printf("\nO valor do salario bruto e: %.2f\nFoi subitraido: %.2f de inss\nFoi subitraido: %.2f de imposto de renda\nSendo: %.2f o salário liquido.", bruto, inss, leao, liquido);
}

int main(){
    apresentacao();
    tudo();    
    
    return 0;
}