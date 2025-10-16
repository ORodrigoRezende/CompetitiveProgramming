#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char pais[50];
    char frase[100];
}Frases;

int achaPais(Frases *lista,char * pais,int tam){
    for (int i = 0; i < tam; i++){
        if(strcmp(pais,lista[i].pais)==0){
            printf("%s\n",lista[i].frase);
            return 0;
        }
    }return 1;
}

int main(){
   Frases lista[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };
    int tam = sizeof(lista) / sizeof(lista[0]);
    char * pais = (char*)malloc(sizeof(char*)*50);
    while(scanf("%s",pais)!=EOF){
        if(achaPais(lista,pais,tam)==1) printf("--- NOT FOUND ---\n");
    }

    return 0;
}