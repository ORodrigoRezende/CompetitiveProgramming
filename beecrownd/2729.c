#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[21];
}Item;

void troca(Item* a, Item *b){
   Item aux = *a;
   *a = *b;
   *b = aux;
}

int particao(Item *v, int ini, int fim){
    int i = ini, j = fim;
    char pivo[21]; 
    strcpy(pivo, v[(ini + fim) / 2].nome);
    while (1) {
        while(strcmp(v[i].nome, pivo) < 0){ i++; }
        while(strcmp(v[j].nome, pivo) > 0){ j--; } 
        
        if(i<j){
            troca(&v[i], &v[j]); 
            i++;
            j--;
        }else
            return j; 
    }    
}

void QuickSort(Item *v, int ini, int fim){
    if(ini < fim ){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q+1, fim);
    }
}

int palavraNaoIgual(Item *v,char *palavra,int qtd){
    for (int i = 0; i < qtd; i++){
        if(strcmp(palavra,v[i].nome)==0) return 0;
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++){
        char buf[25000];
        Item * lista = (Item*)malloc(sizeof(Item)*1001);
        fgets(buf,25000,stdin);
        buf[strcspn(buf, "\n")] = 0;
        int cont=0;
        char *palavra;
        palavra = strtok(buf," ");
        while (palavra!=NULL){
            if(palavraNaoIgual(lista,palavra,cont)){
                snprintf(lista[cont].nome, sizeof(lista[cont].nome), "%s", palavra);
                cont++;
            }
            palavra = strtok(NULL," ");
        }
        if (cont > 0) { 
            QuickSort(lista, 0, cont - 1);
        }
        for (int i = 0; i < cont; i++){
            if(i==cont-1){
                printf("%s",lista[i].nome);
            }else{
                printf("%s ",lista[i].nome);
            }
        }
        printf("\n");
        free(lista);
    }
}