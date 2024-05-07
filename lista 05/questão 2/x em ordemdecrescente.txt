#include <stdio.h>

int main() {

  int n;

  printf("digite ate qual valor quer:");
  scanf("%d", &n);

  for(int i = 0; i <= n; i++){

    while(i < n){
      n--;
      printf("%d\n", n);
    }
  }
  return 0;
}
