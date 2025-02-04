#include <stdio.h>
#include <stdlib.h>
void apresentacao(){
    printf("\nsequencia recursiva de um a 5\n\n");
}
void umAcinco(int x){
    
    printf("%d", x);

    if(x < 5){
    umAcinco(x + 1);
    }   

    printf("%d", x);
}

int main(){
    apresentacao();
    umAcinco(1);
    return 0;
}
