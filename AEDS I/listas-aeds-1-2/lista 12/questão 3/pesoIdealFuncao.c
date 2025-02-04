#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPeso Ideal\n");
}

char lerGenero(){
    char genero;
    bool erro;
    
    do{
        printf("\nDigite o genero da pessoa (f/m): ");
        scanf(" %c", &genero);
        erro = (genero != 'f' && genero != 'F' && genero != 'm' && genero != 'M');
        if(erro){
            printf("\nGenero invalido (f/m): ");
        }
    }while (erro);
    
    
    
    return genero;
}

int lerIdade(){
    
    int idade;
    bool erro;

    do{
    printf("Digite a idade da pessoa: ");
    scanf("%d", &idade);
    erro = (idade <= 0);
    if(erro){
        printf("\nIdade inválida");
    }
    }while(erro);
    
    return idade;
}

float lerAltura(){
    
    float altura;
    
    printf("Digite a altura da pessoa: ");
    scanf("%f", &altura);
    
    return altura;
}

float calcularPesoIdeal(char genero, float altura){
    float pesoIdeal;
    if(genero == 'f' || genero == 'F'){
        pesoIdeal = (62.1 * altura) - 44.7; 
    }
    else if(genero == 'm' || genero == 'M'){
        pesoIdeal = (72.2 * altura) - 58;
    }

    return pesoIdeal;
}

void printPesoIdeal(){
    char genero = lerGenero(); 
    float altura = lerAltura();
    
    int idade = lerIdade();

    float pesoIdeal = calcularPesoIdeal(genero, altura);
    printf("\nO Peso Ideal da pessoa e: %.2f", pesoIdeal);
}

 char opcaoDeContinuar(){
    char continuar;
    printf("\n\nQuer calcular o peso ideal de outra pessoa? (s/n): ");
    scanf(" %c", &continuar);
    return continuar;
}

int main(){
    apresentacao();

    char continuar;

    do{ 
        printPesoIdeal();
        continuar = opcaoDeContinuar();
    }while(continuar == 's' || continuar == 'S');
    
    
    return 0;
}
