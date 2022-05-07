#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int h;
    int m;
    int s;
}time;

typedef struct{
    char id[10];
    time h1;
    time h2;
}alpiniste;

typedef struct{
    int num;
    float dist;
    alpiniste A[3];
}station;

typedef struct Cellule{
    station s;
    struct Cellule *suiv;
    struct Cellule *prec;
}cellule;

typedef struct ListeDC{
    cellule *tete;
    cellule *queu;
}LDC;

void menu(int *ch);

/** Partie I **/

void initchemin(LDC *l);
station saisir_station();
int liste_vide(LDC l);
cellule* chercher_station(LDC l, int num);
/** Add Station Functions! **/
LDC ajouter_debut(LDC l, station s);
LDC ajouter_fin(LDC l, station s);
LDC ajouter_station(LDC l);
/** **********************  **/
void Afficher_Chemin(LDC l);
void initialiser_alpiniste(LDC l, alpiniste *a);
LDC init_competition(LDC l);

/** Partie II **/

/** Delete Station Functions! **/
LDC supprimer_debut(LDC l);
LDC supprimer_fin(LDC l);
LDC supprimer_station(LDC l);
/** **********************  **/
void suivre_montee_alpiniste(cellule *parc, char id[]);
void suivre_descente_alpiniste(cellule *parc, char id[]);
void suivre_alpiniste(LDC l);
void afficher_avancement(LDC l);
int calculer_duree_escalade(LDC l, char id[], int *des, int *mont);
void gagnant_Escalade(LDC l);

#endif // FUNCTIONS_H_INCLUDED