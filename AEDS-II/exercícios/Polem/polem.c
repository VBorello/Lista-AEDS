#include <stdio.h>

int removerPolem(int n){
    
    int qtd = 0;

    if(n == 0){
        return 1;
    } 

    while(n != 0){
        qtd++;    
        n /= 10;
    }

    return qtd;
}

int main(){

    int n, posicao;
    scanf("%d %d", &n, &posicao);

    int flores[n];
    
    for(int i = 0; i < n; i++){
        scanf("%d", &flores[i]);
    }

    int polem = flores[posicao - 1];
    
    int digitos = removerPolem(polem);
    int resultado = polem - digitos;

    printf("%d\n", resultado);

    return 0;
}
