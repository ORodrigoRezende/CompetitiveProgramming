#include <stdio.h>
 
int main() {
 
    double x;
    int y = 0;
    
    for (int i = 1; i <= 6; i++)
    {
      scanf("%lf",&x);
      if(x>0){
        y++;
      }
    }
    
    printf("%d valores positivos\n",y);
    
    return 0;
}