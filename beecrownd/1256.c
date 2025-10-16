#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;    
}NO;

typedef struct NO* Lista;

typedef struct{
    Lista **tabela;
    int tam, qtd;
}Hash;

Lista* criaLista(){
    Lista *li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;//True - Vazia!
    return 0;//False - tem elemento!
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}


void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        return;
    }
    NO* aux = *li;
    while(aux != NULL){
        printf("-> %d ", aux->info);
        aux = aux->prox;
    }
}

void destroiLista(Lista* li){
    if(li != NULL){
        NO* aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}


Hash* criaHash(int t){
    Hash* h;
    h = (Hash*) malloc (sizeof(Hash));
    if(h != NULL){
        h->tam = t; h->qtd = 0;
        h->tabela = (Lista**) malloc (t*sizeof(Lista*));
        if(h->tabela == NULL) return NULL;
        int i;
        for(i = 0; i<t; i++)
            h->tabela[i] = NULL;
    }
    return h;
}


void destroiHash(Hash *h){
    if(h != NULL){
        int i;
        for(i = 0; i<h->tam; i++)
            if(h->tabela[i] != NULL)
                destroiLista(h->tabela[i]);
        free(h->tabela);
        free(h);
    }
}

int chaveDivisao(int chave, int tam){
    return (chave & 0x7FFFFFFF) % tam;
}

int insereHashLSE(Hash* h, int elem){
    if(h == NULL) return 0;
    int pos = chaveDivisao(elem, h->tam);
    if(h->tabela[pos] == NULL)
        h->tabela[pos] = criaLista();
    insereFim(h->tabela[pos], elem);
    h->qtd++;
    return 1;
}

void imprimeHash(Hash *h){
    if(h == NULL) return;
    int i;
    for(i=0; i<h->tam; i++){
        printf("%d ", i);
        imprimeLista(h->tabela[i]);
        printf("-> \\\n");
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        int chave, qtd,x;
        scanf("%d %d",&chave,&qtd);
        Hash *H;
        H = criaHash(chave);
        for (int j = 0; j < qtd; j++){
            scanf("%d",&x);
            insereHashLSE(H,x);
        }
        imprimeHash(H);
        if(i!=n-1) printf("\n");
        destroiHash(H);
    }
    return 0;
}
