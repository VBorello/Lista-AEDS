//Ler um conjunto de salários e conceder reajustes de acordo com os seguintes critérios:
//- Salários inferiores a um mil reais, acréscimo de dez por cento.
//- Salários entre um mil e dois mil reais, acréscimo de oito por cento.
//- Salários acima de dois mil reais, acréscimo de sete por cento.
//Para cada salário lido, calcular e escrever o percentual de reajuste e o valor do salário reajustado.
//Em seguida, deverá ser verificado com o usuário de seu programa se há mais salários a serem fornecidos
//[S/N]. Repetir o processo enquanto ele responder que sim (respondendo ‘S’).
//Ao manifestar o desejo de finalizar (respondendo ‘N’) , deverá ser informado o salário médio após as
//correções salariais.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nRajustes Salariais\n\n");
}

void lerQuantidade(int* quantidade){
    printf("Digite quantos salarios irão ser lidos: ");
    scanf("%d", quantidade);
}

void lerSalario(float* salario, int quantidade){
    
    for(int i = 0; i < quantidade; i++){
        printf("Digite o valor do salário %d: ", i + 1);
        scanf("%f", &salario[i]);
    }
}

void reajusteSalarial(float* salario, int quantidade, float* reajuste, float* somaSalarios){
    for(int i = 0; i < quantidade; i++){
        if(salario[i] < 1000){
            reajuste[i] = salario[i] / 100 * 10;
        }
        else if(salario[i] >= 1000 && salario[i] <= 2000){
            reajuste[i] = salario[i] / 100 * 8;
        }
        else if(salario[i] > 2000){
            reajuste[i] = salario[i] / 100 * 7;
        }

        float salarioReajustado = salario[i] + reajuste[i];
        *somaSalarios += salarioReajustado;
        printf("\nO salário %d no valor de %.2f foi reajustado para %.2f, com reajuste de %.2f%%", i + 1, salario[i], salarioReajustado, (reajuste[i] / salario[i]) * 100);
    }
}

int main(){
    apresentacao();

    int quantidade;
    lerQuantidade(&quantidade);
    float somaSalarios = 0;

    float* salario = (float *)malloc(quantidade * sizeof(float));
    float* reajuste = (float *)malloc(quantidade * sizeof(float));

    lerSalario(salario, quantidade);
    reajusteSalarial(salario, quantidade, reajuste, &somaSalarios);


    free(salario);
    free(reajuste);

    return 0;
}