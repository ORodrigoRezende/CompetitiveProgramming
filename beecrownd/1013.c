#include <stdio.h>
 
int main() {
 
    /**
     * Escreva a sua solução aqui
     * Code your solution here
     * Escriba su solución aquí
     */
    int A;
    int B;
    int C;
    int AB;
    int ABC;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    AB = (A+B+abs(A-B))/2;
    ABC = (AB+C+abs(AB-C))/2;
    printf("%d eh o maior\n", ABC);
    return 0;
}