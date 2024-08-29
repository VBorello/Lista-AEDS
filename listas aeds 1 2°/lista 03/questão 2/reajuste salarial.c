#include <stdlib.h>
#include <stdio.h>

void apresentacao(){
    printf("\nReajuste salarial\n\n");
}

void lerCargo(int* cargo){

    printf("\nDigite o código do cargo:");
    printf("\n0 - Sair\n1 - Escrituário\n2 - Secretário\n3 - Caixa\n4 - Gerente\n5 - Diretor\n: ");
    scanf("%d", cargo);
}

void lerSalario(int* salario){

    printf("\nDigite o salário:");
    scanf("%d", salario);
}

void reajuste(){

    int reajuste;
    int salario;
    
    int cargo;
    

    do{

        lerCargo(&cargo);
        
        switch (cargo){
        case 0:{
            printf("\nsaindo...");
            exit;
        }

        break;

        case 1:{
            lerSalario(&salario);
            reajuste = salario * 50 / 100;
            salario += reajuste;

            printf("\nO salário reajustado do Escrituário é de: %d\n", salario);
        }
            
        break;

        case 2:{
            lerSalario(&salario);
            reajuste = salario * 35 / 100;
            salario += reajuste;

            printf("\nO salário reajustado do Secretário é de: %d\n", salario);
        }
            
        break;

        case 3:{
            lerSalario(&salario);
            reajuste = salario * 20 / 100;
            salario += reajuste;

            printf("\nO salário reajustado do Caixa é de: %d\n", salario);
        }
            
        break;
        
        case 4:{
            lerSalario(&salario);
            reajuste = salario * 10 / 100;
            salario += reajuste;

            printf("\nO salário reajustado do Gerente é de: %d\n", salario);
        }
            
        break;
        
        case 5:{
            printf("\nDiretores não irão ter o salário reajustado\n");
        }
            
        break;
        
        default:

            printf("\nOpção inválida");

            break;
        }
    }while (cargo != 0);    
}

int main(){

    apresentacao();
    reajuste();

    return 0;
}