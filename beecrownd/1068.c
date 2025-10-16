#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

typedef struct{
    int qtd, ini, fim;
    int dados[MAX];
}Fila;


Fila* criaFila(){
    Fila* fi;
    fi = (Fila*) malloc (sizeof(Fila));
    if(fi != NULL){
        fi->qtd = fi->ini = fi->fim = 0;
    }
    return fi;
}

void destroiFila(Fila *fi){
    if(fi != NULL)
        free(fi);
}

int estaCheia(Fila *fi){
    if(fi == NULL)
        return -1;
    return (fi->qtd == MAX);
}
int estaVazia(Fila *fi){
    if(fi == NULL)
        return -1;
    return (fi->qtd == 0);
}

int enfileirar(Fila* fi, int elem){
    if(fi == NULL) return 0;
    if(estaCheia(fi)) return 0;
    fi->dados[fi->fim] = elem;
    fi->fim = (fi->fim+1) % MAX;
    fi->qtd++;
    return 1;
}

int desenfileirar(Fila* fi){
    if(fi == NULL) return 0;
    if(estaVazia(fi)) return 0;
    fi->ini = (fi->ini+1) % MAX;
    fi->qtd--;
    return 1;
}


int main(){
    char linha[1001];
    while (fgets(linha,sizeof(linha),stdin)){
        Fila *f = criaFila();
        int i=0;
        int valido = 1;
        while (linha[i]!='\0'){
            if (linha[i]=='('){
                enfileirar(f,1);
            }else if(linha[i] == ')'){
                if (!desenfileirar(f)) {
                    valido = 0;
                    break;
                }
            }
            i++;
        }
        if(valido && estaVazia(f)){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
        destroiFila(f);
    }
    return 0;
}