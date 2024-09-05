#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nEstatistica Salarial Empresarial\n\n");
}

void lerQtdFuncionarios(int* qtd){
    printf("Digite a quantidade de funcionários: ");
    scanf("%d", qtd);
}

void lerSalarioMin(int* minimo){
    printf("\nDigite o salário minimo pago pela empresa: ");
    scanf("%d", minimo);
}

void lerSalario(int* salarios, int qtd){
    
    for(int i = 0; i < qtd; i++){
        printf("\nQual o salario do %d funcionário: ", i + 1);
        scanf("%d", &salarios[i]);
    }
}

int percentualMinimo(int* salarios, int qtd, int minimo){
  
    int recebedoresDoMinimo = 0;
    for(int i = 0; i < qtd; i++){
        if(salarios[i] == minimo){
            recebedoresDoMinimo++;
        } 
    }

    return recebedoresDoMinimo;
}

int amplitudeSalarial(int* salarios, int qtd, int minimo){
    
    int maior = 0; 
    int menor = 100000000;
    for(int i = 0; i < qtd; i++){
        if(salarios[i] > maior){
           maior = salarios[i];
        }
        if(salarios[i] < menor){
            menor = salarios[i];
        }
    }
    int amplitude = maior - menor;

    return amplitude;
}

int main(){
    
    apresentacao();
    int salarioMinimo;
    int funcionarios;
    int amplitude, recebedoresDoMinimo;

    lerSalarioMin(&salarioMinimo);
    lerQtdFuncionarios(&funcionarios);

    int* salarios = (int *)malloc(funcionarios * sizeof(int));
    lerSalario(salarios, funcionarios);

    recebedoresDoMinimo = percentualMinimo(salarios, funcionarios, salarioMinimo);
    amplitude = amplitudeSalarial(salarios, funcionarios, salarioMinimo);

    printf("\nA quantidade de funcionarios que recebem um salario mínimo e: %d", recebedoresDoMinimo);
    printf("\nA amplitude salarial da empresa e: %d", amplitude);

    free(salarios);

    return 0;
}