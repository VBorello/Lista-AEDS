#include <stdio.h>
#include <stdlib.h>

void apresentacao(){
    printf("\nK-esimo termo de fibonacci\n\n");
}

int lerTermo(){
    int termo;
    printf("digite de qual numero deseja comecar o fibonacci:");
    scanf("%d", &termo);
    return termo;
}

int ateTermo(){
    int ate;
    printf("digite quantos termos deseja ver:");
    scanf("%d", &ate);
    return ate;
}

int fibonacci(int n1, int n2, int ate){
    if(ate == 0){
        return n1;
    }
    
    return fibonacci(n2, n1 + n2, ate - 1);
}

int main(){
    apresentacao();

    int termo = lerTermo();
    int ate = ateTermo();

    printf("os %d termos da sequencia de fibonacci a partir de %d sao:\n", ate, termo);
    
    for (int i = 0; i < ate; i++){
        printf("%d\n", fibonacci(termo, termo + 1,i));
    } 
    return 0;
}
   