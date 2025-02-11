#include <stdlib.h>
#include <stdio.h>

int valorX(){

    int x = 5;

    return x--;
}

int valorY(){

    int y = 5;

    return --y;
}



int main(){

    int x = valorX();
    int y = valorY();


    printf("\n%d\n%d", x, y);

    return 0;
}