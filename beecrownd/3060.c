#include <stdio.h>

int main(){
    int valor,parcela,prestacao,ad,pread;
    scanf("%d",&valor);
    scanf("%d",&parcela);
    if(valor%parcela == 0){
        prestacao = valor/parcela;
        for(int i=0;i<parcela;i++){
            printf("%d\n",prestacao);
        }
    }else{
        ad = valor%parcela;
        
        prestacao = valor/parcela; 
        pread = prestacao+1;
        for(int i=0;i<parcela;i++){
            if(ad>0){
                ad--;
                printf("%d\n",pread);
            }else{
                printf("%d\n",prestacao);
            }
            
        }
    }
    return 0;
}