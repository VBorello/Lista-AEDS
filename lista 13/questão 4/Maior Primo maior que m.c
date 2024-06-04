#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nPrimo antecessor e sucessor de M\n\n");
}

bool primo(int num){
    if(num <= 1){
        return false;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void encontrePrimos(int m, int *p1, int *p2){
    *p1 = m - 1;
    while(*p1 >= 2 && !primo(*p1)){
        (*p1)--;    
    } 

    *p2 = m + 1;
    while(!primo(*p2)){
        (*p2)++;
    }
}
int lerM(){
    int m;
    printf("Qual o Valor de M(maior do que 1):");
    scanf("%d", &m);
    return m;
}
int main(){

    apresentacao();
    
    int m, p1, p2;
    m = lerM();

    encontrePrimos(m, &p1, &p2);

    printf("o maior primo menor que %d e: %d\n", m, p1);
    printf("o menor primo maior que %d e: %d", m, p2);

    return 0;
}