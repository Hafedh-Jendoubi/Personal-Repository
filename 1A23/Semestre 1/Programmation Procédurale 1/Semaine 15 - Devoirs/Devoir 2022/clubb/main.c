#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Club.h"

int main()
{
    int nbC=0, choix;
    club TabC[50], C;
    adherent A;
    char Mat[20];

    printf("-------Gestion des Clubs--------\n");
    printf("1: Ajouter un club\n");
    printf("2: Afficher les clubs\n");
    printf("3: Inscrire un adherent dans un club donne\n");
    printf("0: Quitter\n");

    do{
        do{
            printf("Veuillez introduire votre choix: ");
            scanf("%d", &choix);
        }while((choix<0)||(choix>3));

        switch(choix)
        {
        case 1:
            ajouter_club(TabC, &nbC, C); break;

        case 2:
            afficher_clubs(TabC, nbC); break;

        case 3:
            printf("Matricule du Club: "); scanf("%s", Mat);
            Inscrire_Adherent(TabC, nbC, Mat, A); break;

        }
    }while(choix!=0);

    return 0;
}
