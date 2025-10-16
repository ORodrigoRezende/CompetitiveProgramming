#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */int v[10];
    
    for(int i=0;i<10;i++){
       scanf("%d ",&v[i]);
    }
    for(int i=0;i<10;i++){
        if(v[i]<=0){
            v[i] = 1;
        }
        printf("X[%d] = %d\n",i,v[i]);
    }
 
    return 0;
}