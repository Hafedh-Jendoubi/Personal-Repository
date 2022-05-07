#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct{
    char id[20];
    char nom[30];
    char adresse[30];
    int nb_voyage;
}voyageur;

void MenuDisplay();
void Choice(int *choix);
void DisplayLoadingData();
int nbVoyageurs(char nomFich[]);
void saisirVoyageur(voyageur *ptv);
voyageur* charger_donnees(char nomFich[], int *n);
void tester(voyageur *tab, int n);
void sauvegarder_donnees(char nomFich[], voyageur *tab, int n);
int trouver(voyageur *tab, char id[], int n);
voyageur* ajouter(voyageur v, voyageur *tab, int *n);
void supprimer(voyageur *tab , char id[], int *n);
void liberer(voyageur *tab);

#endif // FONCTIONS_H_INCLUDED
