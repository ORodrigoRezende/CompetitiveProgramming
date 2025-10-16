#include <stdio.h>

int main(){
    int c,l;
    scanf("%d",&c);
    scanf("%d",&l);
    if(c%2==0 && l%2!=0 || c%2!=0 && l%2==0){
        printf("0\n");
    }else{
        printf("1\n");
    }
    return 0;
}