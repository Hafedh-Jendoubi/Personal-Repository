#include "functions.h"

int main()
{
    int ch=-1;
    abr a = NULL;
    etudiant e;

    a = initialiser(e);
    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                taper_etudiant(&e); inserer(a, e); break;

            case 2:
                afficher(a); break;
        }
    }while(ch!=0);

    return 0;
}