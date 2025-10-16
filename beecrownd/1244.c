#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char palavra[51];
    int tam;
}String;

void troca(String* a, String *b){
   String aux = *a;
   *a = *b;
   *b = aux;
}

void Merge(String *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    String *A = (String*) malloc (tam*sizeof(String));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i].tam >= v[j].tam){ 
            A[k] = v[i];
            i++; 
        }
        else { 
            A[k] = v[j]; 
            j++; 
        }
        k++;
    }
    while (i<=meio) { 
        A[k] = v[i];
        i++;  k++; 
        }
    while (j<=fim) {
        A[k] = v[j];
        j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++){
         v[i] = A[k];
         }
    free(A);
}

void MergeSort(String *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}

void imprimeVetor(String* v,int tam){
    for(int i=0;i<tam;i++){
        printf("%s",v[i].palavra);
         if (i < tam - 1){
            printf(" ");
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char buf[2600];
    for (int i = 0; i < n; i++){
        String* lista = (String*)malloc(sizeof(String)*51);
        fgets(buf,2600,stdin);
        buf[strcspn(buf, "\n")] = 0;
        int cont=0;
        char *palavra;
        palavra = strtok(buf," ");
        while (palavra!=NULL){
            snprintf(lista[cont].palavra, sizeof(lista[cont].palavra), "%s", palavra);
            lista[cont].tam = strlen(lista[cont].palavra);
            cont++;
            palavra = strtok(NULL," ");
        }
        MergeSort(lista,0,cont-1);
        imprimeVetor(lista,cont);
        printf("\n");
    }
    
    return 0;
}