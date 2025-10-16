#include <stdio.h>
 
int main() {
 
    double n1,n2,n3,n4,media,nexame;
    scanf("%lf %lf %lf %lf",&n1,&n2,&n3,&n4);
   
      media = ((n1*2) + (n2*3) + (n3*4) +(n4*1))/10;
      printf("Media: %.1lf\n",media);
      if(media >= 7){
         printf("Aluno aprovado.\n");
      }else if(media >= 5 && media <7){
         printf("Aluno em exame.\n");
         scanf("%lf",&nexame);
         printf("Nota do exame: %.1lf\n",nexame);
         media = (media + nexame)/2;
         if(media>= 5.0){
            printf("Aluno aprovado.\n");
         }else if(media<5.0){
            printf("Aluno reprovado.\n");
         }
         printf("Media final: %.1lf\n",media);

      }else{
         printf("Aluno reprovado.\n");
      }
 
    return 0;
}