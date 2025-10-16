#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char** a, char **b){
   char* aux = *a;
   *a = *b;
   *b = aux;
}

int particao(char **v, int ini, int fim){
    int i = ini, j = fim;
    char *pivo = v[(ini + fim) / 2];

    while (1) {
        while(strcmp(v[i], pivo) < 0){ i++; }
        while(strcmp(v[j], pivo) > 0){ j--; }

        if(i < j){
            troca(&v[i], &v[j]);
            i++;
            j--;
        } else {
            return j;
        }
    }
}

void QuickSort(char **v, int ini, int fim){
    if(ini < fim){
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q + 1, fim);
    }
}

int main(){
    int n;int prim=1;
    while (scanf("%d", &n) == 1 && n != 0){
        if(!prim)printf("\n");
        prim=0;
        while (getchar() != '\n');

        int bp = 0, bm = 0, bg = 0, vp = 0, vm = 0, vg = 0;
        char tamanho;
        char cor[10];
        char nome[1000];

        char** brancoP = (char**)malloc(sizeof(char*) * n);
        char** brancoM = (char**)malloc(sizeof(char*) * n);
        char** brancoG = (char**)malloc(sizeof(char*) * n);
        char** vermelhoP = (char**)malloc(sizeof(char*) * n);
        char** vermelhoM = (char**)malloc(sizeof(char*) * n);
        char** vermelhoG = (char**)malloc(sizeof(char*) * n);

        if (!brancoP || !brancoM || !brancoG || !vermelhoP || !vermelhoM || !vermelhoG) {
            fprintf(stderr, "Erro de alocação de memória!\n");
            return 1;
        }

        for (int i = 0; i < n; i++){

            fgets(nome, 1000, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            scanf("%s %c", cor, &tamanho);
            while (getchar() != '\n');

            if (strcmp(cor, "branco") == 0){
                if (tamanho == 'P'){
                    brancoP[bp] = (char*)malloc(strlen(nome) + 1);
                    if (brancoP[bp]) strcpy(brancoP[bp], nome);
                    bp++;
                } else if (tamanho == 'M'){
                    brancoM[bm] = (char*)malloc(strlen(nome) + 1);
                    if (brancoM[bm]) strcpy(brancoM[bm], nome);
                    bm++;
                } else if (tamanho == 'G'){
                    brancoG[bg] = (char*)malloc(strlen(nome) + 1);
                    if (brancoG[bg]) strcpy(brancoG[bg], nome);
                    bg++;
                }
            } else if (strcmp(cor, "vermelho") == 0){
                if (tamanho == 'P'){
                    vermelhoP[vp] = (char*)malloc(strlen(nome) + 1);
                    if (vermelhoP[vp]) strcpy(vermelhoP[vp], nome);
                    vp++;
                } else if (tamanho == 'M'){
                    vermelhoM[vm] = (char*)malloc(strlen(nome) + 1);
                    if (vermelhoM[vm]) strcpy(vermelhoM[vm], nome);
                    vm++;
                } else if (tamanho == 'G'){
                    vermelhoG[vg] = (char*)malloc(strlen(nome) + 1);
                    if (vermelhoG[vg]) strcpy(vermelhoG[vg], nome);
                    vg++;
                }
            }
        }

        QuickSort(brancoP, 0, bp - 1);
        QuickSort(brancoM, 0, bm - 1);
        QuickSort(brancoG, 0, bg - 1);
        QuickSort(vermelhoP, 0, vp - 1);
        QuickSort(vermelhoM, 0, vm - 1);
        QuickSort(vermelhoG, 0, vg - 1);

        for (int i = 0; i < bp; i++){
            printf("branco P %s\n", brancoP[i]);
        }
        for (int i = 0; i < bm; i++){
            printf("branco M %s\n", brancoM[i]);
        }
        for (int i = 0; i < bg; i++){
            printf("branco G %s\n", brancoG[i]);
        }
        for (int i = 0; i < vp; i++){
            printf("vermelho P %s\n", vermelhoP[i]);
        }
        for (int i = 0; i < vm; i++){
            printf("vermelho M %s\n", vermelhoM[i]);
        }
        for (int i = 0; i < vg; i++){
            printf("vermelho G %s\n", vermelhoG[i]);
        }
        

        for (int i = 0; i < bp; i++) free(brancoP[i]);
        free(brancoP);
        for (int i = 0; i < bm; i++) free(brancoM[i]);
        free(brancoM);
        for (int i = 0; i < bg; i++) free(brancoG[i]);
        free(brancoG);
        for (int i = 0; i < vp; i++) free(vermelhoP[i]);
        free(vermelhoP);
        for (int i = 0; i < vm; i++) free(vermelhoM[i]);
        free(vermelhoM);
        for (int i = 0; i < vg; i++) free(vermelhoG[i]);
        free(vermelhoG);
    }
    return 0;
}