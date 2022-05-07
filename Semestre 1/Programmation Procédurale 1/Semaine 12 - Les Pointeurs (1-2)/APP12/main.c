#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int choix, n=0, ref, n_rep=0, n_nrep=0;
    machine m, Tm[50];
    panne p;


    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                saisir(&m); break;

            case 2:
                ajouter(Tm, m, &n); break;

            case 3:
                printf("%d\n", rechercherMach(Tm, n, taperref(ref))); break;

            case 4:
                saisirPanne(&p); break;

            case 5:
                ajouterPanne(taperref(ref), Tm, n, p); break;

            case 6:
                printf("%d\n", totalPanne(taperref(ref), Tm, n)); break;

            case 7:
                modifier_etat_panne(taperref(ref), Tm, n); break;

            case 8:
                afficher(n, Tm, taperref(ref)); break;

            case 9:
                trouver(Tm, n, &n_rep, &n_nrep, taperref(ref)); break;

            case 10:
                /** Will finish it **/ break;
        }
    }while(choix!=0);

    return 0;
}
