#include <stdio.h>

int main(){
    int x=1,cont=0,aldo=0,beto=0,y,z;
    do
    {
        cont++;
        scanf("%d",&x);
        if(x!=0){
            for (int i = 0; i < x; i++)
        {
            scanf("%d %d",&y,&z);
            aldo+=y;
            beto+=z;
        }
        if(aldo>beto){
            printf("Teste %d\n",cont);
            printf("Aldo\n\n");
        }else{
            printf("Teste %d\n",cont);
            printf("Beto\n\n");
        }
        }  
        aldo=0;
        beto=0;
        
    } while (x!=0);
    return 0;
}