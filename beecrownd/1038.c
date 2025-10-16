#include <stdio.h>
 
int main() {
 
    int codigo,quanti;
    double valortotal;
    
   scanf("%d %d",&codigo,&quanti);

    if(codigo == 1){
        valortotal = 4.0*quanti;
    }else if(codigo == 2){
        valortotal = 4.5*quanti;
    }else if(codigo == 3){
        valortotal = 5.0*quanti;
    }else if(codigo == 4){
        valortotal = 2.0*quanti;
    }else if(codigo == 5){
        valortotal = 1.5*quanti;
    }
    printf("Total: R$ %.2lf\n",valortotal);
 
    return 0;
}