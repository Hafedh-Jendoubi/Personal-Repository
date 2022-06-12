#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    char nom[20];
    char prenom[20];
    int rdv;
}Patient;

struct cellule{
    Patient p;
    struct cellule *suivant;
};

typedef struct cellule *liste;

void Test(liste tete);
void saisirPatient(Patient *p);
void afficherPatient(Patient p);
void RendezVous(liste tete, int *rdv, int *sansRdv);
liste SupprimePatient(liste tete);
void ConsulterSalleAttente(liste tete);
void sauvegarderPatients(liste tete, char chemin[]);
liste recupererListePatients(liste tete, char chemin[]);

#endif // FUNCTIONS_H_INCLUDED
