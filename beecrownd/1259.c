#include <stdio.h>
#include <stdlib.h>

void Merge(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] < v[j]){ A[k] = v[i]; i++; }
        else { A[k] = v[j]; j++; }
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++){ v[i] = A[k];}
    free(A);
}

void MergeSort(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSort(v, ini, meio);
        MergeSort(v, meio+1, fim);
        Merge(v, ini, meio, fim);
    }
}

void MergeC(int *v, int ini, int meio, int fim){
    int tam = fim-ini+1;
    int *A = (int*) malloc (tam*sizeof(int));
    int i = ini, j = meio+1, k = 0;
    while (i<=meio && j<=fim) {
        if (v[i] > v[j]){ A[k] = v[i]; i++; }
        else { A[k] = v[j]; j++; }
        k++;
    }
    while (i<=meio) { A[k] = v[i];  i++;  k++; }
    while (j<=fim) { A[k] = v[j];  j++;  k++; }
    for(i = ini, k=0; i<=fim; i++, k++){ v[i] = A[k];}
    free(A);
}

void MergeSortC(int *v, int ini, int fim){
    if(ini < fim ){
        int meio = (ini + fim)/2;
        MergeSortC(v, ini, meio);
        MergeSortC(v, meio+1, fim);
        MergeC(v, ini, meio, fim);
    }
}

int main(){
    int n,p=0,i=0;
    scanf("%d",&n);
    if(n>0){
        int *vp = (int*) malloc(n * sizeof(int));
        int *vi = (int*) malloc(n * sizeof(int));
        if (vp == NULL || vi == NULL) {
            return 1; 
        }

        for (int j = 0; j < n; j++){
            int temp;
            scanf("%d",&temp);
            if(temp%2==0){
                vp[p] = temp;
                p++;
            }else{
                vi[i] = temp;
                i++;
            }
        }
        if (p > 0) {
            MergeSort(vp, 0, p - 1); }
        if (i > 0) {
            MergeSortC(vi, 0, i - 1); }
        for (int j = 0; j < p; j++){
            printf("%d\n",vp[j]);
        }
        for (int j = 0; j < i; j++){
            printf("%d\n",vi[j]);
        }
        free(vp);
        free(vi);
    }
    return 0;
}