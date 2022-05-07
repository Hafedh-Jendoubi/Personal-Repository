#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main()
{
    int choix, n;
    char filename[20] = "nombre_enfants.txt", prenom[20];


    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                remplir_employes(filename); break;

            case 2:
                printf("Taper le prenom a chercher: "); scanf("%s", prenom);
                chercher_employe(filename, prenom); break;

            case 3:
                printf("Taper le nombre d'enfant de ce employe: "); scanf("%d", &n);
                afficher_employee_nenfant(filename, n); break;

            case 4:
                supprimer_employee_0enfant(filename); break;
        }
    }while(choix!=0);

    return 0;
}
