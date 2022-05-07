#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    char refpanne[30];
    int etat;
}panne;

typedef struct
{
    int refmachine;
    panne P[10];
}machine;

void menuprincipal();
int menu(); /** Je fais deux menus pour éviter la répition de l'affichage du menu principal! **/
void saisir(machine *m);
void ajouter(machine Tm[], machine m, int *n);
int rechercherMach(machine Tm[], int n, int ref);
void saisirPanne(panne *p);
int taperref(int ref);
void ajouterPanne(int ref, machine Tm[], int n, panne p);
int totalPanne(int ref, machine Tm[], int n);
void modifier_etat_panne(int ref, machine Tm[], int n);
void afficher(int n, machine Tm[], int ref);
void trouver(machine Tm[], int n, int *n_rep, int *n_nrep, int ref);
void supprimer(machine Tm[], int *n); /** will finish it **/

#endif // FONCTIONS_H_INCLUDED
