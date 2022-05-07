#include "functions.h"

int main()
{
    int ch=-1, val;
    Arbre R=NULL;

    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                printf("Taper une Valeur a ajouter: "); scanf("%d", &val);
                R = AjouterNoeudABR(R, val); break;

            case 2:
                ParcoursPrefixe(R); break;

            case 3:
                ParcoursInfixe(R); break;

            case 4:
                ParcoursPostfixe(R); break;
        }
    }while(ch!=0);

    return 0;
}