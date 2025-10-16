#include <stdio.h>

int main(){
    char op;
    double m[12][12],soma=0;
    int aux1=1,aux2=10;
    scanf("%c",&op);
    for (int i = 0; i < 12; i++){
        for (int j = 0;  j< 12; j++){
            scanf("%lf",&m[i][j]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = aux1; j <= aux2; j++)
        {
                soma += m[j][i];
        }
        aux1++;
        aux2--;
    }
    if(op=='S'){
        printf("%.1lf\n",soma);
    }else if(op =='M'){
        printf("%.1lf\n",soma/30);
    }
    return 0;
}