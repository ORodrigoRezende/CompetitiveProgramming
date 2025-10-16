#include <stdio.h>
#include <math.h>

int main() {
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        int eh_primo = 1; 

        if (x <= 1) {
            eh_primo = 0;  
        } else {
            for (int j = 2; j <= sqrt(x); j++) {
                if (x % j == 0) {
                    eh_primo = 0;  
                    break;
                }
            }
        }

        if (eh_primo == 1) {
            printf("%d eh primo\n", x);
        } else {
            printf("%d nao eh primo\n", x);
        }
    }

    return 0;
}