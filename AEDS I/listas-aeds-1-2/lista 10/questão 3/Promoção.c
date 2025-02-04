//Para liquidar o estoque, uma empresa buscou uma promoção que possa atrair bastante os clientes. Para
//isso, elaborou uma política de descontos agressiva, concedendo um desconto de setenta por cento para
//itens com valores abaixo de quinhentos reais; de sessenta por cento para itens entre quinhentos e três mil
//reais e de cinquenta por cento para itens acima de três mil reais.
//Para cada valor lido, calcular e escrever o valor promocional, com o devido desconto.
//Flag para finalização: valor do item igual a zero.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nDescontos Agressivos\n\n");
}

int main(){
    apresentacao();

    float precos = 1;
    float desconto;
    float reajuste;
    
     while(precos != 0){
        printf("Digite o valor do item: ");
        scanf("%f", &precos);

        if(precos < 500 && precos > 0){
            desconto = precos / 100 * 70;
            reajuste = precos - desconto;
            printf("\nO produto de valor %.2f teve um desconto de %d%% passando a valer %.2f\n\n", precos, 70, reajuste);
        }
        else if(precos <= 500 && precos < 3000 && precos > 0){
            desconto = precos / 100 * 60;
            reajuste = precos - desconto;
            printf("\nO produto de valor %.2f teve um desconto de %d%% passando a valer %.2f\n\n", precos, 60, reajuste);
        }
        else if(precos >= 3000 && precos > 0){
            desconto = precos / 100 * 50;
           reajuste = precos - desconto;
            printf("\nO produto de valor %.2f teve um desconto de %d%% passando a valer %.2f\n\n", precos, 50, reajuste);
        }
        else{
            printf("\nsaindo...");
        }
    }


    return 0;
}