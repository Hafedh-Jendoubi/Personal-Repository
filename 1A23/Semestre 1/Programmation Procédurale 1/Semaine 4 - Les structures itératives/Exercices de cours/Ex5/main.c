#include <stdio.h>

int main()
{
    int choix;

    printf("~~~~~~~~~~~~~~   Types de plats   ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~     1- Pizza       ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~  2- Plat Escalope  ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~   3- Plat Poulet   ~~~~~~~~~~~~~~\n");
    printf("~~~~~~~~~~~~~~  4- Plat Grillade  ~~~~~~~~~~~~~~\n\n");

    do{
    printf("Choisissez un plat: "); scanf("%d", &choix);
    }while((choix<=0)||(choix>=5));

    switch(choix){
        case 1: printf("Vous avez choisi Pizza!"); break;
        case 2: printf("Vous avez choisi Plat Escalope!"); break;
        case 3: printf("Vous avez choisi Plat Poulet!"); break;
        case 4: printf("Vous avez choisi Plat Grillade!"); break;
    }

    return 0;
}
