#include <stdio.h>
 
int main() {
 
    double salario,x,imposto,imposto2,imposto3;

    scanf("%lf",&salario);

    if (salario>=0 && salario<=2000.0)
    { 
      printf("Isento\n");

    }else if(salario>2000 && salario<=3000){
      
      x = salario - 2000;
      imposto = x * 0.08;
      printf("R$ %.2lf\n",imposto);

    }else if(salario>3000 && salario<=4500){

      imposto = 1000 * 0.08;
      x = salario - 3000;
      imposto2 = (x * 0.18) + imposto;
      printf("R$ %.2lf\n",imposto2);

    }else {
      imposto = 1000 * 0.08;
      imposto2 = 1500 * 0.18;
      x = salario - 4500;
      imposto3 = imposto+imposto2+ (x*0.28);
      printf("R$ %.2lf\n",imposto3);
    }
    
    return 0;
}