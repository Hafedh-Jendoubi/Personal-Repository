#include "functions.h"

int main()
{
    int choix, a=0;
    file f;

    f = initFile();
    menuprincipal();
    do{
        choix = menu();
        switch(choix){
            case 0:
                printf("...\n"); break;

            case 1:
                test(f); break;

            case 2:
                f = ajouter_client(f); break;

            case 3:
                f = servir_client(f, &a); break;

            case 4:
                printf("La recette totale: %d\n", a); break;
        }
    }while(choix!=0);

    return 0;
}
