#include <stdio.h>

int main(){
    int n[6],v[6],cont=0;
    scanf("%d %d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5]);
    scanf("%d %d %d %d %d %d",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5]);
    for(int i=0; i<6;i++){
        for(int j=0;j<6;j++){
            if(n[j]==v[i]){
                cont++;
            }
        }
    }
    if(cont==3){
        printf("terno\n");
    }else if(cont==4){
        printf("quadra\n");
    }else if(cont==5){
        printf("quina\n");
    }else if(cont==6){
        printf("sena\n");
    }else{
        printf("azar\n");
    }


    return 0;
}