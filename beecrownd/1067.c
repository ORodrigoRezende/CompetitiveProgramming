#include <stdio.h>
 
int main() {
 
    int x;
    scanf("%d",&x);
    for (int i = 1; i <= x; i=i+2)
    {
      printf("%d\n",i);
    }
 
    return 0;
}