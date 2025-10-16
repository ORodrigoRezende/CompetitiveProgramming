#include <stdio.h>

int main(){

    int num[15],par[5],impar[5];
    int cont=0,cont2=0;

    for (int i = 0; i < 15; i++)
    {
        scanf("%d",&num[i]);
        if(num[i]%2==0){
            par[cont]=num[i] ;
            cont++;
            if(cont>=5){
                for (int i = 0; i < 5; i++){
                printf("par[%d] = %d\n",i,par[i]);
                par[i]="\0" ; 
                cont=0;     
                }
            }
        }else if(num[i]%2!=0){
            impar[cont2]=num[i];
            cont2++;
            if(cont2>=5){
                for (int i = 0; i < 5; i++){
                printf("impar[%d] = %d\n",i,impar[i]);
                impar[i]="\0" ;    
                cont2=0  ;
                }
            }
        }
    }
    for (int i = 0; i < cont2; i++){
            printf("impar[%d] = %d\n",i,impar[i]);       
    }
    for (int i = 0; i < cont; i++){
            printf("par[%d] = %d\n",i,par[i]);       
    }
    return 0;
}