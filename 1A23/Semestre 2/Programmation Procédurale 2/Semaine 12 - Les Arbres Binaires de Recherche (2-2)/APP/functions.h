#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int id; 
    char nom[20];
    char prenom[20];
    int niveau; 
    float moy;
}etudiant;

struct Noeud{
    etudiant e;
    struct Noeud *FG;
    struct Noeud *FD;
};

typedef struct Noeud *abr;

void menu(int *ch);
abr initialiser(etudiant e);
void taper_etudiant(etudiant *e);
abr inserer(abr a, etudiant e);
abr construireArbre(abr a, char nomFich[]);
void afficher(abr a);

#endif // FUNCTIONS_H_INCLUDED