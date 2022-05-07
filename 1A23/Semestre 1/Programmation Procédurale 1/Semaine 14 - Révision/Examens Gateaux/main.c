#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int choix, tg=0, type, pos, matV[3][7], jour;
    gateau g, tabG[20];
    float tabP[7];

    initialiser(matV, tabP);
    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                saisir(&g);
                ajouterGateau(tabG, g, &tg); break;

            case 2:
                afficher(tabG, tg); break;

            case 3:
                do{
                    printf("Taper le type: "); scanf("%d", &type);
                }while((type<0)||(type>2));
                trouver(tabG, tg, type, &pos);
                printf("%d\n", pos); break;

            case 4:
                break;
        }
    }while(choix!=0);

    return 0;
}
