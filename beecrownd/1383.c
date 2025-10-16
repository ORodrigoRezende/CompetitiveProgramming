#include <stdio.h>

int verifica(int m[9][9]){
    int ocorrencias[10];
    int lq=0,cq=0;
    for(int c=0;c<3;c++){
        for (int l = 0; l < 3; l++){   
            for (int k = 0; k < 10; k++) ocorrencias[k] = 0;
            for(int i = lq; i < lq+3; i++){
                for (int j = cq; j < cq+3; j++){
                int num= m[i][j];
                    if (num < 1 || num > 9 || ocorrencias[num]++) {
                        return 0;
                    }
             }
            
            } 
        lq+=3;
    }
    lq=0;
    cq+=3;
    }
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 10; k++) ocorrencias[k] = 0;
        for (int j = 0; j < 9; j++) {
            int num = m[i][j];
            if (num < 1 || num > 9 || ocorrencias[num]++) {
                return 0;
            }
        }

        for (int k = 0; k < 10; k++) ocorrencias[k] = 0;
        for (int j = 0; j < 9; j++) {
            int num = m[j][i];
            if (num < 1 || num > 9 || ocorrencias[num]++) {
                return 0;
            }
        }
    }
    return 1;
}



int main(){
    int instancias;
    scanf("%d",&instancias);
    
    for (int k = 1; k <= instancias; k++)
    {
        int m[9][9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                scanf("%d",&m[i][j]);
        }
        }
        if(verifica(m)==0){
            printf("Instancia %d\n",k);
            printf("NAO\n\n");
        }else{
            printf("Instancia %d\n",k);
            printf("SIM\n\n");
        }
    }
}