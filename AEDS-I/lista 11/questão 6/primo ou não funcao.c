#include <stdio.h>
#include <stdbool.h>

void apresentacao(){
printf("\nPrimo ou Nao\n\n");
}

bool ePrimo(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i * i <= n; i++){
        if(n % 1 == 0){
            return false;
        }
    }
    return true;
}

int leianum(){
    int n;
    printf("digite um numero:");
    scanf("%d", &n);
    return n;
}
int main(){
    apresentacao();
    int num = leianum(); 
    if (ePrimo(num)){
        printf("%d e um numero primo", num);
    }
    else{
        printf("%d nao e primo", num);
    }
return 0;
}



