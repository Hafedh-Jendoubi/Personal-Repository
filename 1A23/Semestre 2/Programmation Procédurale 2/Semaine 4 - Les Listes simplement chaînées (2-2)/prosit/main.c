#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int num=0, choix;
    liste l = NULL;
    wagon w;

    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                afficherTrain(l); break;

            case 2:
                l = ajouterLocomotive(l, saisirLocomotive(w)); break;

            case 3:
                l = ajouterWagon(l, saisirWagon(w)); break;

            case 4:
                printf("Taper le numero du wagon: "); scanf("%d", &num);
                printf("%d\n", rechercherWagon(l, num)); break;

            case 5:
                l = SupprimerWagonPanne(l); break;

            case 6:
                printf("Taper le numero du wagon: "); scanf("%d", &num);
                l = ajouterWagonDonne(l, saisirWagon(w), num); break;

            case 7:
                l = liberer(l); break;
        }
    }while(choix!=0);

    return 0;
}
