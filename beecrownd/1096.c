#include <stdio.h>
 
int main() {
 
    for (int i = 1; i <= 9; i=i+2)
    {
      for (int x = 7; x >=5; x--)
      {
       printf("I=%d J=%d\n",i,x);
      }
      
    }
 
    return 0;
}