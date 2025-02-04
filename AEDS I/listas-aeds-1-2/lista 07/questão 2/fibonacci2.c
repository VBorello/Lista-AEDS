#include <stdio.h>
#include <stdlib.h>


int main(){

    int a = 0, b, c;
    b = a + 1;
    int n = 0;
    printf("\nQuantos termos de fibonacci você irá ver: ");
    scanf("%d", &n);
    printf("\n");

    for(int i = 0; i < n; i++){

        c = a + b;
        a = b;
        b = c;
       
        printf(" %d ", c);
    }

    return 0;

}