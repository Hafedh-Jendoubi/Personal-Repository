#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

int main()
{
    int choix, nE=3;
    espece tabE[100];
    animal a;
    char nomE[20];

    remplirEspeces(tabE, nE); system("cls");
    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                printf("Nom de l'espece: "); scanf("%s", nomE);
                ajouterAnimal(a, nomE, tabE, nE); break;
        }
    }while(choix!=0);

    return 0;
}
