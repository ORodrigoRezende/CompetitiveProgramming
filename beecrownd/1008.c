#include <stdio.h>
 
int main() {
 
    int num,horas;
    double valorhr,salario;
    
    scanf("%d",&num);
    scanf("%d",&horas);
    scanf("%lf",&valorhr);
    
    salario = valorhr*horas;
    
    printf("NUMBER = %d\n",num);
    printf("SALARY = U$ %.2lf\n",salario);
    
    return 0;
}