#include <stdio.h>

int main(){
    double matriz[12][12];
    char Op;
    double soma=0;
    scanf("%c",&Op);
    getchar();

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%lf",&matriz[i][j]);
        }
        
    }
    if (Op == 'S')
    {
        for(int i = 7; i < 12; i++)
        {
            for (int j = 11 -i+1; j <= i-1; j++)
            {
                    soma+= matriz[i][j];
            }
        }
        
    }else if (Op == 'M')
    {
        int cont =0;
        for(int i = 7; i < 12; i++)
        {
            for (int j = 11 -i+1; j <= i-1; j++)
            {
                    soma+= matriz[i][j];
                    cont++;
            }
        }
        soma = soma/cont;
    }
    
    printf("%.1lf\n",soma);


    return 0;
}