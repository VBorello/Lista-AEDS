#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>  // Inclua esta biblioteca para a função sleep()

void apresentacao(){
    printf("\nCalculadora de x Valores\n\n");
}

void lerTermos(int* termos){
    
    printf("\nQuantos termos terá sua operaçao:");
    scanf("%d", termos);
}

float soma(int termos){

    float numeros;
    float soma = 0;
    for(int i = 0; i < termos; i++){
        printf("\nDigite o %d termo:", i + 1);
        scanf("%f", &numeros);
        soma += numeros;
    }

    return soma;
}

float subtracao(int termos){

    float numeros;
    float subtracao = 0;
    for(int i = 0; i < termos; i++){
        printf("\nDigite o %d termo:", i + 1);
        scanf("%f", &numeros);
        if(i == 0){
            subtracao = numeros;
        }
        else{
            subtracao -= numeros;
        }
    }
    
    return subtracao;
}

float multiplicacao(int termos){

    float numeros;
    float multiplicacao = 1;
    for(int i = 0; i < termos; i++){
        printf("\nDigite o %d termo:", i + 1);
        scanf("%f", &numeros);
        multiplicacao *= numeros;
    }
    
    return multiplicacao;
}

float divisao(int termos){

    float numeros;
    float divisao = 0;
    for(int i = 0; i < termos; i++){
        printf("\nDigite o %d termo:", i + 1);
        scanf("%f", &numeros);
        if(i == 0){
            divisao = numeros; 
        }
        else if(numeros == 0){
            printf("\nErro divisao por 0");
            return -1;
        }
        else{
            divisao /= numeros;
        }
    }

    return divisao;
}

float potenciacao(){

    float base;
    int expoente;

    printf("\nDigite a base:");
    scanf("%f", &base);
    printf("\nDigite o expoente:");
    scanf("%d", &expoente);

    float potencia = 1;
    for(int i = 0; i < expoente; i++){
        potencia *= base;
    }

    return potencia;
}
 
int fatorial(){
    
    int n = 1;
    int fat;
    
    printf("\nDigite o numero fatorial:");
    scanf("%d", &fat);

    if (fat < 0) {
        printf("Erro: Número fatorial não pode ser negativo!\n");
        return -1;
    }
    
    for(int i = 0; i < fat; i++){
        n *= fat;
    }
    
    return n;
}


void menu(){

    int opcao, termos;
    float resultado;

    do{//começo

        printf("'0' para sair\n'1' para soma\n'2' para subtraçao\n'3' para divisao\n'4' para multiplicaçao\n'5' para potenciacao\n'6' para fatorial\n:");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            printf("\nsaindo...\n");
            sleep(1);
            break;
        case 1:
            lerTermos(&termos);
            resultado = soma(termos);
            printf("\nO resultado da soma e: %.2f\n\n", resultado);

            break;
        case 2:
            lerTermos(&termos);
            resultado = subtracao(termos);
            printf("\nO resultado da subtracao e: %.2f\n\n", resultado);

            break;
        case 3:
            lerTermos(&termos);
            resultado = divisao(termos);
            printf("\nO resultado da multiplicacao e: %.2f\n\n", resultado);

            break;
        case 4:
            lerTermos(&termos);
            resultado = multiplicacao(termos);
            printf("\nO resultado da divisao e: %.2f\n\n", resultado);
    
            break;
        case 5:
            resultado = potenciacao();
            printf("\nO resultado da potenciação e: %d\n", (int)resultado);
            break;
        case 6:
            resultado = fatorial();
            printf("\nO fatorial e igual a: %d\n", (int)resultado);
            break;
        default: 
            printf("\nopcao invalida\n\n");
            break;
        }

    }while (opcao != 0); //fim   
}

int main(){

    apresentacao();
    menu();
    system("clear");

    return 0;
}