#include <stdio.h>

void removeAreia(char *linha,int i){
    while (linha[i+1]!= '\0'){
        linha[i] = linha [i+1];
        i++;
    }
    linha[i] = '\0';
}

int main(){
    int x;
    scanf("%d",&x);
    getchar();
    char linha[1001];
    for (int i = 0; i < x; i++){
        int j=0,y=0,k=0,z=0;
        fgets(linha,sizeof(linha),stdin);
        while (linha[j]!= '\0'){
            if(linha[j]=='.'){
                removeAreia(linha,j);
            }else{
                j++;
            }
        }
        while (linha[k]!= '\0'){
            if (linha[k]=='<'){
                z++;
            }else if(linha[k] == '>'){
                if (z>0) {
                    z--;
                    y++;
                }
            }
            k++;
        }
        printf("%d\n",y);
        
    }
    


    return 0;
}