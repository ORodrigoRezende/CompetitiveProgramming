#include <stdio.h>

int main(){
    char op;
    double m[12][12],soma=0;
    int aux=11;
    scanf("%c",&op);
    for (int i = 0; i < 12; i++){
        for (int j = 0;  j< 12; j++){
            scanf("%lf",&m[i][j]);
        }
    }
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (j<aux)
            {
                soma += m[i][j];
            }
        }
        aux--;
    }
    if(op=='S'){
        printf("%.1lf\n",soma);
    }else if(op =='M'){
        printf("%.1lf\n",soma/66);
    }
    return 0;
}