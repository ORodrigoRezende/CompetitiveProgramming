#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char palavra1[101],palavra2[101],palavra3[101],R1[303],R2[303],R3[303],R4[31]="";
    fgets(palavra1,101,stdin);
    fgets(palavra2,101,stdin);
    fgets(palavra3,101,stdin);

    palavra1[strcspn(palavra1, "\n")] = '\0';
    palavra2[strcspn(palavra2, "\n")] = '\0';
    palavra3[strcspn(palavra3, "\n")] = '\0';

    strcpy(R1,palavra1);
    strcat(R1,palavra2);
    strcat(R1,palavra3);

    strcpy(R2,palavra2);
    strcat(R2,palavra3);
    strcat(R2,palavra1);

    strcpy(R3,palavra3);
    strcat(R3,palavra1);
    strcat(R3,palavra2);

    strncat(R4, palavra1, 10); 
    strncat(R4, palavra2, 10); 
    strncat(R4, palavra3, 10);

    printf("%s\n",R1);
    printf("%s\n",R2);
    printf("%s\n",R3);
    printf("%s\n",R4);
    return 0;
}