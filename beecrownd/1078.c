#include <stdio.h>
 
int main() {
 
    int n, x;
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
    {
      x = i * n;
      printf("%d x %d = %d\n",i,n,x);
    }

    return 0;
}