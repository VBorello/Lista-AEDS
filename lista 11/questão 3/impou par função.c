#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
    printf("\nInteiro Impar ou Par funcao\n\n");
}

int leiaNum(){
    int n;
    printf("Digite um numero:");
    scanf("%d", &n);
    
    return n;
}

bool ePar(int n){
    bool par = false;
    
    if(n % 2 == 0){
        par = true;
    }

    return par;

}


int main(){
    apresentacao();
    int num = leiaNum();

    if(ePar(num) == true){
        printf("o numero e par");
    }else{
        printf("o numero e impar");
    }

    return 0;
}