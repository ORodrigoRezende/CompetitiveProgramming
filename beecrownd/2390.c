#include <stdio.h>

int main(){
    int x,temp,total=0;
    scanf("%d",&x);
    int segundos[x];
    for(int i=0;i<x;i++){
        scanf("%d",&segundos[i]);
    }
    
    for(int i=1;i<x;i++){ 
        temp = segundos[i-1] +10;
        if(temp>segundos[i]){
            total+=segundos[i]-segundos[i-1];

        }else{
            total=total+10;
        }
    }
    total+=10;
    printf("%d\n",total);
    return 0;
}