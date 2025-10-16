#include <stdio.h>
 
int main() {
 
    int n,x,y;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
      x = i * i;
      y = x*i;
      printf("%d %d %d\n",i,x,y);
    }
 
    return 0;
}