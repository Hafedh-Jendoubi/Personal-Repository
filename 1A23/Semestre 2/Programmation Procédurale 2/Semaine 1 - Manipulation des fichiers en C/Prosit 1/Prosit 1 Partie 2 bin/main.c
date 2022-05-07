#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main()
{
    int choix, n;
    FILE *Pbin, *fptrbin;
    char prenom[20];


    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                remplir_employes(Pbin); break;

            case 2:
                printf("Taper le prenom a chercher: "); scanf("%s", prenom);
                chercher_employe(Pbin, prenom); break;

            case 3:
                printf("Taper le nombre d'enfant de ce employe: "); scanf("%d", &n);
                afficher_employee_nenfant(Pbin, n); break;

            case 4:
                supprimer_employee_0enfant(Pbin, fptrbin); break;
        }
    }while(choix!=0);

    return 0;
}
