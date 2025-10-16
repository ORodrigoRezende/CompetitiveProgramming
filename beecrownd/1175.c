#include <stdio.h>

int main(){

    int x[20],y[20];

    for (int i = 19; i >= 0; i--)
    {
        scanf("%d",&x[i]);
    }
    for (int i = 0; i < 20; i++){
            printf("N[%d] = %d\n",i,x[i]);       
    }
    return 0;
}