#include <stdio.h>


int main(){
    unsigned short tam,i;
    char palavra[501];

    scanf("%[^\n]",palavra);

    i = 0;
	while (palavra[i++]){
        tam++;
    }

    if(tam>140){
        printf("MUTE\n");
    }else{
        printf("TWEET\n");
    }
    return 0;
}