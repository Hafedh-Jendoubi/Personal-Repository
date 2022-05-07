#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int prix_tot;
    int mode_payment;
}client;

typedef struct cellule cellule;

struct cellule{
    client c;
    cellule *suivant;
};

struct file{
    cellule *tete;
    cellule *queu;
};

typedef struct file file;

void menuprincipal();
int menu();
file initFile();
client saisir_client();
file ajouter_client(file f);
file servir_client(file f, int *a);

#endif // FUNCTIONS_H_INCLUDED
