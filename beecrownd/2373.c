#include <stdio.h>

int main(){
    int x,copo,lata,cont=0;
    scanf("%d",&x);
    for(int i=0;i<x;i++){
        scanf("%d %d",&lata,&copo);
        if(lata>copo){
            cont+=copo;
        }
    }
    printf("%d\n",cont);
    return 0;
}