#include <stdio.h>
 
int main() {
 
    double r,pi,volume;
    
    scanf("%lf",&r);
    pi = 3.14159;
    volume = (4.0/3.0) * pi * (r*r*r);
    
    printf("VOLUME = %.3lf\n",volume);
 
    return 0;
 
}