#include <stdio.h>

int main() {
    int valor, notas50, notas10, notas5, notas1, cont = 0;

    do {
        cont++;
        scanf("%d", &valor);

        if (valor == 0) { 
            break;
        }

        notas50 = valor / 50; 
        valor %= 50;          
        notas10 = valor / 10; 
        valor %= 10;          
        notas5 = valor / 5;   
        valor %= 5;          
        notas1 = valor;

        printf("Teste %d\n", cont);
        printf("%d %d %d %d\n\n", notas50, notas10, notas5, notas1);

    } while (1); 

    return 0;
}
