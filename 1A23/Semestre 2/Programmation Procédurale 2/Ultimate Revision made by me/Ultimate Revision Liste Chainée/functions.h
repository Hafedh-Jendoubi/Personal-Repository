#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

typedef struct{
    char nom[10];
    int age;
    float cash;
}client;

struct cellule{
    client c;
    struct cellule *suivant;
};

typedef struct cellule *liste;

void afficher_clients(liste l);
/** Functions about Adding Clients!! **/
client saisir_client();
liste ajouter_client_premier(liste l);
liste ajouter_client_apres(liste l);
liste ajouter_client_fin(liste l);
/** Functions about Deleting Clients!! **/
liste supprimer_client_premier(liste l);
liste supprimer_client_nom(liste l);
liste supprimer_client_fin(liste l);
liste supprimer_tous(liste l);
/** Functions about Searching Clients!! **/
void search_client_name(liste l);
void search_client_age(liste l);
void search_client_cash(liste l);
void search_oldest_client(liste l);
void search_youngest_client(liste l);
void search_richest_client(liste l);
void search_poorest_client(liste l);

#endif // FUNCTIONS_H_INCLUDED
