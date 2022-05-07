#include "functions.h"

int main()
{
    int ch=-1;
    LDC l;

    initchemin(&l);
    do{
        menu(&ch);
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                l = ajouter_station(l); break;

            case 2:
                l = supprimer_station(l); break;

            case 3:
                Afficher_Chemin(l); break;

            case 4:
                l = init_competition(l); break;

            case 5:
                suivre_alpiniste(l); break;

            case 6:
                afficher_avancement(l); break;

            case 7:
                gagnant_Escalade(l); break;
        }
    }while(ch!=0);

    return 0;
}