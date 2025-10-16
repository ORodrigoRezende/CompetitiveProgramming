#include <stdio.h>
 
int main() {
 
    char nome[50];
    double fixo,vendas,salariototal;
    
    scanf("%s",&nome);
    scanf("%lf",&fixo);
    scanf("%lf",&vendas);
    
    salariototal = fixo + (vendas*0.15);
    
    printf("TOTAL = R$ %.2lf\n",salariototal);
    
    return 0;
}