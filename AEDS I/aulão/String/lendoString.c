#include <stdio.h>
#include <stdlib.h>

int main(){

    char str[50];
    printf("\nDigite uma palavra");

    fgets(stdin, str);
    
    printf(" %s", str);

    return 0;
}