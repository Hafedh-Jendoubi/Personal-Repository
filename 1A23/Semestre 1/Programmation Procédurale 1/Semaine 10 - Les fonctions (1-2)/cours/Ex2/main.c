#include <stdio.h>
#include <stdlib.h>

int Menu();

int main()
{
    int choix;
    choix = Menu();

    switch(choix)
    {
        case 1:
            printf("Plat choisi: Salade\n");
            break;
        case 2:
            printf("Plat choisi: Grillades\n");
            break;
        case 3:
            printf("Plat choisi: Lasagne\n");
            break;
        case 4:
            printf("Plat choisi: Pizza\n");
            break;
    }

    return 0;
}

int Menu()
{
    int choix;

    do
    {
        printf("\t\t\t******* Menu *******\n");
        printf("1- Salade\n");
        printf("2- Grillades\n");
        printf("3- Lasagne\n");
        printf("4- Pizza\n");
        printf("Veuillez introduire votre choix: "); scanf("%d", &choix);
    }while(choix<1 || choix>4);

    return choix;
}
