#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Ajouter une nouvelle aide\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)&&(choix>1));

    return choix;
}

int verifier_exit(aide TA[], int nA, char designation[])
{
    int i, verif = -1;

    for(i=0; i<nA; i++){
        if(strcmp(designation, TA[i].designation)==0){
            verif = i;
        }
    }

    return verif;
}

void saisir_aide(aide *A)
{
    printf("Designation: "); fflush(stdin); gets((*A).designation);
    printf("Type: "); fflush(stdin); gets((*A).type);
    printf("Quantite disponible: "); scanf("%d", &(*A).quantitedisp);
}

void ajouter_aide(aide TA[], int *nA, aide A)
{
    int verif, choix, qt, i;

    saisir_aide(&A);
    verif = verifier_exit(TA, *nA, A.designation);
    for(i=0; i<(*nA); i++){
        TA[i].quantitedisp=0;
    }
    if(verif == -1){
        TA[(*nA)] = A;
        (*nA)++;
    }else{
        printf("Cette designation existe deja!\nVoulez vous mettre a jour la quantite existante? ([0] Non - [1] Oui)"); scanf("%d", &choix);
        switch(choix){
            case 0:
                printf("Vous avez gardee la quantite existante de la designation %s egale a: %d.\n", TA[verif].designation, TA[verif].quantitedisp);
                break;

            case 1:
                printf("Donner la quantite a ajouter: "); scanf("%d", &qt);
                TA[verif].quantitedisp += qt;
                printf("La nouvelle quantite pour la designation %s est egal a: %d\n", TA[verif].designation, TA[verif].quantitedisp);
                break;

            default:
                printf("Invalid choix!\n"); break;
        }
    }
}
