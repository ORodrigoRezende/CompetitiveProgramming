#include <stdio.h>
 
int main() {
 
    int x,y = 0,z;
    
    for (int i = 1; i <= 100; i++)
    {
      scanf("%d",&x);
      if(x>=y){
        y = x;
        z = i;
      }
    }
    
    printf("%d\n",y);
    printf("%d\n",z);
 
    return 0;
}