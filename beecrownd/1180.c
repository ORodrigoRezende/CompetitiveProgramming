#include <stdio.h>

int main(){
    int x,menor,pos;
    scanf("%d",&x);
    int v[x];
    for (int i = 0; i < x; i++)
    {
        scanf("%d",&v[i]);
        if (i == 0) {
            menor = v[i];
            pos = i;
        } else if (v[i] < menor) {
            menor = v[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\n",menor);
    printf("Posicao: %d\n",pos);

    return 0;
}