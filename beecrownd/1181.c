#include <stdio.h>

int main(){
    int linha;
    char op;
    double m[12][12],soma=0;
    scanf("%d",&linha);
    scanf(" %c",&op);
    for (int i = 0; i < 12; i++){
        for (int j = 0;  j< 12; j++){
            scanf("%lf",&m[i][j]);
        }
    }
    for (int j = 0; j < 12; j++)
    {
        soma+= m[linha][j];
    }
    if(op=='S'){
        printf("%.1lf\n",soma);
    }else if(op =='M'){
        printf("%.1lf\n",soma/12);
    }
    return 0;
}