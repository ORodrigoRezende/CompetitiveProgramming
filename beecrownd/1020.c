#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    int idade,anos,meses,dias;
    scanf("%d",&idade);
    anos= idade/365;
    meses= (idade - anos*365) / 30;
    dias = (idade - anos*365) - (meses*30);
    printf("%d ano(s)\n",anos);
    printf("%d mes(es)\n",meses);
    printf("%d dia(s)\n",dias);
    return 0;
}