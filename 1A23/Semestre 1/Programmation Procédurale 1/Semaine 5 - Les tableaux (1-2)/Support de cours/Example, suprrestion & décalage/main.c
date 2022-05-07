#include <stdio.h>
#include <stdlib.h>


int main() {
   int ligne, colone, i, j, r, l, c, tab[30][30];

   printf("Entrez le nombre des lignes du matrice : ");
   scanf("%d", &ligne);
   printf("Entrez le nombre des colones du matrice :");
   scanf("%d", &colone);

   for (i=0; i<ligne; i++) {
        for(j=0; j<colone; j++){
                tab[i][j]=rand()%100;
        }
   }

    for (i=0; i<5; i++)
        {
          for (j=0; j<10; j++)
            {
               printf("%d", tab[i][j]);
            }
             printf("\n");
        }

   printf(" Entrez l'element à rechercher: ");
   scanf("%d", &r);

   //La recherche commence à partir de zéro
   for(i=0; i<ligne; i++){
    for(j=0; j<colone; j++){
        if(tab[i][j]==r){
            l = i; c = j;
        }
    }
   }

   printf("L'element se trouve dans tab[%d][%d]", l, c);

   return 0;
}
