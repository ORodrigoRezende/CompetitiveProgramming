#include <stdio.h>
 
int main() {
 
    char a,b, c ,d,e, f ,g,h;
    scanf("%c%c%c%c%c%c%c%c",&a,&b,&c,&d,&e,&f,&g,&h);
    printf("%c%c/%c%c/%c%c\n",d,e,a,b,g,h);
    printf("%c%c/%c%c/%c%c\n",g,h,d,e,a,b);
    printf("%c%c-%c%c-%c%c\n",a,b,d,e,g,h);
    
    return 0;
}