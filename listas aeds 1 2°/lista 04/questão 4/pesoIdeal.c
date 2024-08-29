#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){

    printf("\nCalculadora de Peso Ideal\n\n");
}

void lerGenero(char *genero){
    
    bool erro;
    
    do {
        printf("Digite o sexo(F/M):");
        scanf(" %c", genero); 
        erro = (*genero != 'm' && *genero != 'M' && *genero != 'f' && *genero != 'F');
        
        if (erro) {
            printf("\nSexo Invalido\n");
        }
    
    } while (erro);
}

float lerPeso(){
    
    float peso;

    printf("\nDigite o peso:");
    scanf("%f", &peso);

    return peso;
}

float lerAltura(){
    
    float altura;

    printf("\nDigite a alutura:");
    scanf("%f", &altura);

    return altura;
}

void calcularPeso(char genero, float peso, float altura){

    float pesoIdeal;

    if(genero == 'M' || genero == 'm'){
        pesoIdeal = 50 + (2.3 * ((altura * 100) - 152.4)) / 2.54;
    }
    else if(genero == 'f' || genero == 'F'){
        pesoIdeal = 45.5 + (2.3 * ((altura * 100) - 152.4)) / 2.54;
    }

    printf("\no seu peso ideal e: %.2f", pesoIdeal);

}

char continuar(){
    
    char continuar;
    bool erro;
    
    do{
        printf("\n\nquer calcular outro peso ideal?(s/n)");
        scanf(" %c", &continuar);   
        
        erro = (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
        
        if(erro){
            printf("\nopção inválida");
        }
    }
    while(erro);
    
    return continuar;
}

int main(){

    apresentacao();

    char genero;
    char continua;
    float peso, altura;
  
    do{
        lerGenero(&genero);
        altura = lerAltura();
        peso = lerPeso();

        calcularPeso(genero, peso, altura); 

        continua = continuar();

    }while(continua == 's' || continua == 'S');        
    

    return 0;
}