#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    Adherant ad, A[50];
    Constat co, C[2][4];
    int nA=0, *prix, choix;
    int* pnA;

    menuprincipal();
    do{
        choix=menu();
        switch(choix)
        {
            case 0:
                printf("...\n"); break;

            case 1:
                nA = ajouterAdherent(saisirAd(), A, nA); break;

            case 2:
                afficherAdherent(A, nA); break;

            case 3:
                ajouterConstat(C, saisirConstat(A, nA)); break;

            case 4:
                initialiser(C); break;

            case 5:
                afficherConstat(C); break;

            case 6:
                chercherConstat(C); break;

            case 7:
                pnA = &nA; verifierRemboursement(C, A, pnA); break;

            /** Still working on it **/

        }
    }while(choix!=0);

    return 0;
}
