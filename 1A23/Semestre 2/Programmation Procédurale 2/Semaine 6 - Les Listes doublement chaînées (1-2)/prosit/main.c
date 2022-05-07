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
                Afficher_Chemin(l); break;

            case 3:
                l = init_competition(l); break;
        }
    }while(ch!=0);

    return 0;
}