#include <stdio.h>
#include <stdlib.h>

#define MAX 50
typedef struct{
    int qtd;
    int dados[MAX];
}Pilha;

void empilhaAteN(Pilha *p,int x){
    int j=1;
    for (int i = x-1; i >= 0; i--){
        p->dados[i] = j;
        j++;
        p->qtd++;
    }
}

Pilha * criaPilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    return p;
}

int Operacao(Pilha *p){
    int descarte = p->dados[p->qtd-1];
    int temp = p->dados[p->qtd-2];
    for (int i = p->qtd-2; i >0 ; i--){
        p->dados[i] = p->dados[i-1];
    }
    p->qtd--;
    p->dados[0] = temp;
    return descarte;
}

int main(){
    int x=0;
    do{
        scanf("%d",&x);
        if(x!=0){
        int cartas[50],k=0,l=0;
        Pilha *p = criaPilha();
        empilhaAteN(p,x);
        while (p->qtd>1){
            cartas[l]= Operacao(p);
            l++;
        }
        printf("Discarded cards:");
        for (int i = 0; i < l; i++){
            if(i==l-1){
                printf(" %d\n",cartas[i]);
            }else{
                printf(" %d,",cartas[i]);
            }
        }
        printf("Remaining card: %d\n",p->dados[0]);}
    }while(x!=0);
    return 0;
}