#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    famille TF[20];
    aide A, TA[20];
    int choix, nA=0, nF;

    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                ajouter_aide(TA, &nA, A); break;
        }
    }while(choix!=0);

    return 0;
}
