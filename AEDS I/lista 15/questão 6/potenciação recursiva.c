#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nPotenciacao recursiva\n\n");
}

int leiaBase(){
    int base;
    printf("Digite a base da potencia:");
    scanf("%d", &base);
    return base;
}

int leiaExpoente(){
    int expoente;
    printf("Digite o expoente da potencia:");
    scanf("%d", &expoente);
    return expoente;
}

int potenciacao(int base, int expoente){
    if(expoente == 0){ // se não vai dar um stack overflow mané né segredo!
        return 1;
    }
    return base * potenciacao(base, expoente -1);
}

int main(){
    apresentacao();

    int base = leiaBase();
    int expoente = leiaExpoente();

    printf("\%d elevado a %d e: %d", base, expoente, potenciacao(base, expoente));

    return 0;
}