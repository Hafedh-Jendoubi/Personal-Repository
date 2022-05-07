#include "functions.h"

int main()
{
    int ch=-1;
    liste l=NULL;
    ordinateur o;
    file f;

    initFile(&f);
    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                saisirOrdinateur(&o); l = ajouterOrdinateur(l, o); break;

            case 2:
                afficherListe(l, "Liste.txt"); break;

            case 3:
                vendreCaracteristique(&o);
                vendreOrdinateur(l, o.marque, o.taille, o.quantite); break;

            case 4:
                f = enfilerRuptureStock(l, f); break;
        }
    }while(ch!=0);

    return 0;
}