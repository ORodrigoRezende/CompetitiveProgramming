#include <stdio.h>

int main(){
    int coluna;
    char op;
    double m[12][12],soma=0;
    scanf("%d",&coluna);
    scanf(" %c",&op);
    for (int i = 0; i < 12; i++){
        for (int j = 0;  j< 12; j++){
            scanf("%lf",&m[i][j]);
        }
    }
    for (int i = 0; i < 12; i++)
    {
        soma+= m[i][coluna];
    }
    if(op=='S'){
        printf("%.1lf\n",soma);
    }else if(op =='M'){
        printf("%.1lf\n",soma/12);
    }
    return 0;
}