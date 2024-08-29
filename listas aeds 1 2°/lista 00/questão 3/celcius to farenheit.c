#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){

    printf("\nCelcius to fahrenheit ou Kelvin\n\n");
}

void lerCelcio(float* celsius){
    
    printf("digite uma temperatura em graus celsius:");
    scanf("%f", celsius);
}

float calcularFahrenheit(float celsius){
    
    float fahrenheit;
    fahrenheit = celsius * 1.8 + 32;

    return fahrenheit;
}

float calcularKelvin(float celsius){
    
    float kelvin;
    kelvin = celsius + 273.15;

    return kelvin; 
}

void menu(float celsius){
    
    char opcao;
    bool erro;

    do{
        printf("\n'F' para fahrenheit\n'K' para kelvin\n:");
        scanf(" %c", &opcao);
        erro = (opcao != 'F' && opcao != 'f' && opcao != 'k' && opcao != 'K'); 
        if(erro){
            printf("\nOpcao invalida");
        }
    }while (erro);

    if(opcao == 'F' || opcao == 'f'){
        float fahrenheit = calcularFahrenheit(celsius);
        printf("\nA temperatura em fahrenheit e: %.2f", fahrenheit);
    }
    else if(opcao == 'K' || opcao == 'k'){
        float kelvin = calcularKelvin(celsius);
        printf("\nA temperatura em kelvin e: %.2f", kelvin);
    }

}

int main(){

    apresentacao();

    float celsius;
    
    lerCelcio(&celsius);
    menu(celsius);

    return 0;
}