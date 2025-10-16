#include <stdio.h>
 
int main() {
 
    int x,y,z=99999;
    
    for (int i = 1; i <= z; i++)
    {
      scanf("%d %d",&x,&y);
      if(x==y){
        z = i;
      }else if(x>y){
        printf("Decrescente\n");
      }else {
        printf("Crescente\n");
      }
    }
 
    return 0;
}