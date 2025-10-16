#include <stdio.h>
 
int main() {
 
   int hrs,velocidade;
    double litros;

    scanf("%d",&hrs);
    scanf("%d",&velocidade);
    litros = (hrs*velocidade) /12.0;

    printf("%.3lf\n",litros);
 
    return 0;
}