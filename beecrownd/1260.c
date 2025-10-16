#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct NO{
    int qtd, fb, alt;
    char string[31];
    struct NO* esq;
    struct NO* dir;
}NO;

typedef struct NO* AVL;

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

AVL* criaAVL(){
    AVL* raiz = (AVL*) malloc (sizeof(AVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no){
    if(no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiAVL(AVL* raiz){
    if(raiz != NULL){
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(AVL* raiz){
    if(raiz == NULL) return 0;
    return (*raiz == NULL);
}

//Calcula FB
int altura(NO* raiz){
    if(raiz == NULL) return 0;
    if(raiz->alt > 0)
        return raiz->alt;
    else{ 
        //printf("Calculando altura do (%d)..\n", raiz->info);
        return MAIOR(altura(raiz->esq), altura(raiz->dir)) + 1;
    }
}

int FB(NO* raiz){
    if(raiz == NULL) return 0;
    return altura(raiz->esq) - altura(raiz->dir);
}

//Funcoes de Rotacao Simples
void avl_RotDir(NO** raiz){
   NO *aux;
   aux = (*raiz)->esq;
   (*raiz)->esq = aux->dir;
   aux->dir = *raiz;
   
   //Acertando alturas e FB
   //dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);

   *raiz = aux;
}

void avl_RotEsq(NO** raiz){
   NO *aux;
   aux = (*raiz)->dir;
   (*raiz)->dir = aux->esq;
   aux->esq = *raiz;
   
   //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = aux->alt = -1;
    aux->alt = altura(aux); 
    (*raiz)->alt = altura(*raiz); 
    aux->fb = FB(aux); 
    (*raiz)->fb = FB(*raiz);
   
   *raiz = aux;
}


//Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO** raiz){
    NO *fe; //filho esquerdo
    NO *ffd; //filho filho direito
    
    fe = (*raiz)->esq;
    ffd = fe->dir;
    
    fe->dir = ffd->esq;
    ffd->esq = fe;
    
    (*raiz)->esq = ffd->dir;
    ffd->dir = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fe->alt = ffd->alt = -1;
    fe->alt = altura(fe); 
    ffd->alt = altura(ffd);
    (*raiz)->alt = altura(*raiz); 
    fe->fb = FB(fe); 
    ffd->fb = FB(ffd);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffd;
}


void avl_RotDirEsq(NO** raiz){
    NO* fd; //filho direito
    NO* ffe; //filho filho esquerdo

    fd = (*raiz)->dir;
    ffe = fd->esq;
    
    fd->esq = ffe->dir;
    ffe->dir = fd;
    
    (*raiz)->dir = ffe->esq;
    ffe->esq = *raiz;

    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
    (*raiz)->alt = fd->alt = ffe->alt = -1;
    fd->alt = altura(fd); 
    ffe->alt = altura(ffe);
    (*raiz)->alt = altura(*raiz); 
    fd->fb = FB(fd);
    ffe->fb = FB(ffe);
    (*raiz)->fb = FB(*raiz);

    *raiz = ffe;
}

void avl_RotEsqDir2(NO** raiz){
    avl_RotEsq(&(*raiz)->esq);
    avl_RotDir(raiz);
}

void avl_RotDirEsq2(NO** raiz){
    avl_RotDir(&(*raiz)->dir);
    avl_RotEsq(raiz);
}


//Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz){
   NO* fe;
   fe = (*raiz)->esq;
   if(fe->fb == +1) /* Sinais iguais e positivo*/
     avl_RotDir(raiz);
   else /* Sinais diferentes*/
     avl_RotEsqDir(raiz);
}

void avl_AuxFD(NO **raiz){
   NO* fd;
   fd = (*raiz)->dir;
   if(fd->fb == -1) /* Sinais iguais e negativos*/
     avl_RotEsq(raiz);
   else /* Sinais diferentes*/
     avl_RotDirEsq(raiz);
}

int insereRec(NO** raiz, char* string){
    int ok; //Controle para as chamadas recursivas
    if(*raiz == NULL){
        NO* novo = alocarNO();
        if(novo == NULL) return 0;
        novo->qtd = 1;
        strcpy(novo->string,string);
        novo->fb = 0, novo->alt = 1;
        novo->esq = NULL; novo->dir = NULL;
        *raiz = novo; return 1;
        
    }else{
        if(strcmp((*raiz)->string,string)==0){
            ok = 0;
            (*raiz)->qtd++;
        }
        if(strcmp((*raiz)->string,string)>0){
            ok = insereRec(&(*raiz)->esq, string);
            if(ok){
                switch((*raiz)->fb){
                    case -1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = +1; 
                        (*raiz)->alt++; 
                        break;
                    case +1:
                        avl_AuxFE(raiz); ok = 0; break;
                }
            }
        }
        else if(strcmp((*raiz)->string,string)<0){
            ok = insereRec(&(*raiz)->dir, string);
            if(ok){
                switch((*raiz)->fb){
                    case +1:
                        (*raiz)->fb = 0; ok = 0; break;
                    case 0:
                        (*raiz)->fb = -1; (*raiz)->alt++; break;
                    case -1:
                        avl_AuxFD(raiz); ok = 0; break;
                }
            }
        }
    }
    return ok;
}

int insereElem(AVL* raiz, char* string){
    if(raiz == NULL) return 0;
    return insereRec(raiz, string);
}

int pesquisaRec(NO** raiz, char* string){
    if(*raiz == NULL) return 0;
    if(strcmp((*raiz)->string,string)==0) return 1;
    if(strcmp((*raiz)->string,string)>0)
        return pesquisaRec(&(*raiz)->esq, string);
    else 
        return pesquisaRec(&(*raiz)->dir, string);
}

int pesquisa(AVL* raiz, char* string){
    if(raiz == NULL) return 0;
    if(estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, string);
}

int removeRec(NO** raiz, char* string){
    if(*raiz == NULL) return 0;
    int ok;
    if(strcmp((*raiz)->string,string)==0){
        if((*raiz)->qtd>1){
            (*raiz)->qtd--;
            return 1;
        }else{
            NO* aux;
            if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
                //Caso 1 - NO sem filhos
                liberarNO(*raiz);
                *raiz = NULL;
            }else if((*raiz)->esq == NULL){
                //Caso 2.1 - Possui apenas uma subarvore direita
                aux = *raiz;
                *raiz = (*raiz)->dir;
                liberarNO(aux);
            }else if((*raiz)->dir == NULL){
                //Caso 2.2 - Possui apenas uma subarvore esquerda
                aux = *raiz;
                *raiz = (*raiz)->esq;
                liberarNO(aux);
            }else{
                //Caso 3 - Possui as duas subarvores (esq e dir)
                //Duas estrategias:
                //3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
                //3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
                //Estrategia 3.1:
                NO* Filho = (*raiz)->esq;
                while(Filho->dir != NULL)//Localiza o MAIOR valor da subarvore esquerda
                    Filho = Filho->dir;
                strcpy((*raiz)->string,Filho->string);
                int temp = (*raiz)->qtd;
                (*raiz)->qtd = Filho->qtd;
                Filho->qtd = temp;
                return removeRec(&(*raiz)->esq, string);
            }
            return 1;
        }
    }else if(strcmp((*raiz)->string,string)<0){
        ok = removeRec(&(*raiz)->esq, string); 
        if(ok){
            switch((*raiz)->fb){
                case +1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case -1:
                    avl_AuxFD(raiz); break;
            }
        }
    }
    else{ 
        ok = removeRec(&(*raiz)->dir, string);
        if(ok){
            switch((*raiz)->fb){
                case -1:
                case 0:
                    //Acertando alturas e Fatores de Balanceamento dos NOs afetados
                    (*raiz)->alt = -1;
                    (*raiz)->alt = altura(*raiz); 
                    (*raiz)->fb = FB(*raiz);
                    break;
                case +1:
                    avl_AuxFE(raiz); break;
            }
        }
    }
    return ok;
}

int removeElem(AVL* raiz, char* string){
    if(pesquisa(raiz, string) == 0){
        printf("Elemento inexistente!\n");
        return 0;
    }
    return removeRec(raiz, string);
}

void em_ordem(NO* raiz, int nivel,double total){
    if(raiz != NULL){
        em_ordem(raiz->esq, nivel+1,total);
        double porcentagem = ((raiz)->qtd/total) * 100;
        printf("%s %.4lf\n", raiz->string, porcentagem);
        em_ordem(raiz->dir, nivel+1,total);
    }
}

void imprime(AVL* raiz,double total){
    if(raiz == NULL) return;
    em_ordem(*raiz, 0,total);
}

int main(){
    int n, i;
    scanf("%d", &n);
    while(getchar()!= '\n');//Remove o \n da leitura do inteiro.
    char str[100];
    int caso = -1;
    int primeiro = 1;
    for(i=0; i<n; i++){
        AVL* A = criaAVL();
        int total = 0;
        //printf("Caso %d:\n", i+1);
        while(fgets(str, 100, stdin) != NULL){
            if(str[0] == '\n'){
                caso++;
            if(caso > i) break;
            }else{
                int tam = strlen(str);
            if(str[tam-1] =='\n') str[tam-1] = '\0';
                //tam = strlen(str);
                //printf("%s : %d\n", str, tam);
                insereElem(A, str);
                total++;
        }
    }
        if(primeiro){
            primeiro = 0;
        }else printf("\n");
        imprime(A, total);
        destroiAVL(A);
        
    }
    return 0;
}