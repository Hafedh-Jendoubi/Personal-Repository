#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    int choix, nl=0, ne=0, num;
    Livre t_livres[100];
    Emprunt t_emprunts[100];

    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                ajouter_livre(t_livres, &nl); break;

            case 2:
                afficher_livres(t_livres, nl); break;

            case 3:
                ajouter_emprunt(t_emprunts, &ne, t_livres, nl); break;

            case 4:
                printf("Numero de l'emprunt: "); scanf("%d", &num);
                retourner_emprunt(num, t_emprunts, ne, t_livres, nl); break;

            case 5:
                afficher_emprunts_retournes(t_emprunts, ne); break;
        }
    }while(choix!=0);

    return 0;
}
