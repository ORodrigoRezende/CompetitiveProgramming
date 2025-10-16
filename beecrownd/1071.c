#include <stdio.h>
 
int main() {
 
    int n,x,y=0;
    scanf("%d",&n);
    scanf("%d",&x);
    if(x>n){
      for (int i = n+1; i < x; i++)
      {
        if(i%2!= 0){
          y = y+i;
        }
      }
    }else{
      for (int i = x+1; i < n; i++)
      {
        if(i%2!= 0){
          y = y+i;
        }
      }
    }
    printf("%d\n",y);
    
    return 0;
}