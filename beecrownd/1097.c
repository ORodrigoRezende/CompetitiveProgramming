#include <stdio.h>
 
int main() {
 
    int y,z;
  y=7;
  z=5;
    for (int i = 1; i <= 9; i=i+2)
    {
      for (int x = y; x >=z; x--)
      {
       printf("I=%d J=%d\n",i,x);
      }
      y= y+2;
      z= z+2;
    }
 
    return 0;
}