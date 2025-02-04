#include <stdio.h>

int main() 
{
    printf("\n Calculadora \n\n");

    float num1, num2, resultado;
    char operação, continuar;
    continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
    printf(" Digite a operação (+,-,*,/,^):");
    scanf(" %c", &operação);

    printf("Digite o primeiro valor:");
    scanf("%f", &num1);
    printf("Digite o segundo valor:");
    scanf("%f", &num2);

    switch (operação) 
    {
    case '+':
    resultado = num1 + num2;
    printf("Resultado: %.2f\n", resultado);
    break;
    case '-':
    resultado = num1 - num2 ;
    printf("Resultado: %.2f\n", resultado);
    break;
    case '*':
    resultado = num1 * num2;
    printf("Resultado: %.2f\n", resultado);
    break;
    case '/':
    if( num2 != 0) {
    resultado = num1 / num2;
    printf("Resultado: %.2f\n", resultado);
    } 
    else 
    {
    printf("Erro! Divisao por zero nao permitida.\n");      
    }
    break;
    default:
    printf("Operacao invalida!\n");
    } 
    printf("Deseja continuar? (S/N):");
    scanf(" %c",&continuar);
    }

    printf("\nTchal!");
  
    return 0;
}