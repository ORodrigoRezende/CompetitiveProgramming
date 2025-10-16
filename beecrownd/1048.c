#include <stdio.h>
 
int main() {
 
    double salario,newsalario,aumento;

    scanf("%lf",&salario);

    if (salario>=0 && salario<=400.0)
    { 
      aumento = (salario * 0.15);
      newsalario = salario + aumento;
      printf("Novo salario: %.2lf\n",newsalario);
      printf("Reajuste ganho: %.2lf\n",aumento);
      printf("Em percentual: 15 %%\n");

    }else if(salario>400 && salario<=800){
      
      aumento = (salario * 0.12);
      newsalario = salario + aumento;
      printf("Novo salario: %.2lf\n",newsalario);
      printf("Reajuste ganho: %.2lf\n",aumento);
      printf("Em percentual: 12 %%\n");

    }else if(salario>800 && salario<=1200){
      aumento = (salario * 0.10);
      newsalario = salario + aumento;
      printf("Novo salario: %.2lf\n",newsalario);
      printf("Reajuste ganho: %.2lf\n",aumento);
      printf("Em percentual: 10 %%\n");

    }else if(salario>1200 && salario<=2000){
      aumento = (salario * 0.07);
      newsalario = salario + aumento;
      printf("Novo salario: %.2lf\n",newsalario);
      printf("Reajuste ganho: %.2lf\n",aumento);
      printf("Em percentual: 7 %%\n");

    }
    else {
      aumento = (salario * 0.04);
      newsalario = salario + aumento;
      printf("Novo salario: %.2lf\n",newsalario);
      printf("Reajuste ganho: %.2lf\n",aumento);
      printf("Em percentual: 4 %%\n");
    }
    
 
    return 0;
}