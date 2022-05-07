#include "menu.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Show Clients list\n");
        printf("2- Add Clients Menu\n");
        printf("3- Delete Clients Menu\n");
        printf("4- Search Clients Menu\n");
        printf("0- Exit\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>4));
}

void add_menu(liste *l, int *a)
{
    int ch;

    system("cls");
    printf("~~~~~~~~ Adding Menu: ~~~~~~~~\n");
    printf("1- Add Client in the beginning\n");
    printf("2- Add client after a named client\n");
    printf("3- Add client in the back\n");
    printf("0- Back to Main Menu\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>3));
        switch(ch){
            case 0:
                system("cls"); *a = -1; break;

            case 1:
                *l = ajouter_client_premier(*l); break;

            case 2:
                *l = ajouter_client_apres(*l); break;

            case 3:
                *l = ajouter_client_fin(*l); break;
        }
    }while(ch!=0);
}

void warning_check(int *a)
{
    do{
        printf("Voulez-vous continuer? ([0] Non - [1] Oui)\n"); scanf("%d", &*a);
    }while((*a<0)||(*a>1));
}

void delete_menu(liste *l, int *a)
{
    int ch, b;

    system("cls");
    printf("~~~~~~~~ Deleting Menu: ~~~~~~~~\n");
    printf("1- Delete client from the beginning\n");
    printf("2- Delete client by name\n");
    printf("3- Delete client from the back\n");
    printf("4- Delete all the clients [Warning]\n");
    printf("0- Back to Main Menu\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>4));
        switch(ch){
            case 0:
                system("cls"); *a = -1; break;

            case 1:
                *l = supprimer_client_premier(*l); break;

            case 2:
                *l = supprimer_client_nom(*l); break;

            case 3:
                *l = supprimer_client_fin(*l); break;

            case 4:
                warning_check(&b);
                if(b==0){
                    printf("Deleting all Clients has been canceled!\n"); break;
                }else{
                    *l = supprimer_tous(*l); break;
                }
        }
    }while(ch!=0);
}

void search_menu(liste *l, int *a)
{
    int ch;

    system("cls");
    printf("~~~~~~~~ Searching Menu: ~~~~~~~~\n");
    printf("1- Search clients by name\n");
    printf("2- Search clients by age\n");
    printf("3- Search clients by cash interval\n");
    printf("4- Search oldest client(s)\n");
    printf("5- Search youngest client(s)\n");
    printf("6- Search richest client(s)\n");
    printf("7- Search poorest client(s)\n");
    printf("0- Back to Main Menu\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>7));
        switch(ch){
            case 0:
                system("cls"); *a = -1; break;

            case 1:
                search_client_name(*l); break;

            case 2:
                search_client_age(*l); break;

            case 3:
                search_client_cash(*l); break;

            case 4:
                search_oldest_client(*l); break;

            case 5:
                search_youngest_client(*l); break;

            case 6:
                search_richest_client(*l); break;

            case 7:
                search_poorest_client(*l); break;
        }
    }while(ch!=0);
}
