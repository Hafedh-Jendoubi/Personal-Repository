#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int choix, nbJ=0, critere;
    jouet TabJt[100], MatriceJt[4][30];

    menuprincipal(); Initialiser(MatriceJt);
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                AjouterJouet(TabJt, &nbJ); break;

            case 2:
                critere = sousmenu();
                AfficherJouets(TabJt, nbJ, critere); break;

            case 3:
                JouetEnfant(TabJt, nbJ, donner_code()); break;

            case 4:
                TrierJouets(TabJt, nbJ); break;

            case 5:
                MettreEnPlaceMagasin(TabJt, nbJ, MatriceJt); break;
        }
    }while(choix!=0);

    return 0;
}
