#include "functions.h"

int main()
{
    int choix;
    pile p = NULL;
    file f;

    f = initFile();
    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                p = ajouter_dossier(p); break;

            case 2:
                p = retirer_dossier(p); break;

            case 3:
                dernier_dossier(p); break;

            case 4:
                p = permutation(p); break;

            case 5:
                f = deplacer(f, &p); break;

            case 6:
                consulter_file(f); break;

            case 7:
                f = remove_dossier(f); break;
        }
    }while(choix!=0);

    return 0;
}
