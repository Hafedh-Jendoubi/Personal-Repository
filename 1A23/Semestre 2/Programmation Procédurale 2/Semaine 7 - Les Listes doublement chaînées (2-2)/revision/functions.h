#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char marque[10];
    int taille;
    int quantite;
    float prix;
}ordinateur;

typedef struct Cellule{
    ordinateur o;
    struct Cellule *suivant;
}cellule;

typedef struct File{
    cellule *tete;
    cellule *queue; 
}file;

typedef struct Cellule *liste;

void menu(int *ch);
void saisirOrdinateur(ordinateur *o);
cellule* chercherOrdinateur(liste l, char marque[], int taille);
liste ajouterOrdinateur(liste l, ordinateur o);
void afficherListe(liste l, char nomFichier[]);
file enfilerOrdinateur(file f, ordinateur o);
void initFile(file *f);
void vendreCaracteristique(ordinateur *o);
void vendreOrdinateur(liste l, char marque[], int taille, int qte);
file enfilerRuptureStock(liste l, file f);
file approvisionnerOrdinateur(liste l, file f);

#endif // FUNCTIONS_H_INCLUDED