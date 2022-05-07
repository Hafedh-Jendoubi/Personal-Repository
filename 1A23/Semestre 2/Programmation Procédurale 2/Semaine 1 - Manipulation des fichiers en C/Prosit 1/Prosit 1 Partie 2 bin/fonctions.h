#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    char nom[20];
    char prenom[20];
    int nbEnfant;
}employe;

void menuprincipal();
int menu();
void remplir_employes(FILE *Pbin);
void chercher_employe(FILE *Pbin, char prenom[]);
void afficher_employee_nenfant(FILE *Pbin, int n);
void supprimer_employee_0enfant(FILE *Pbin, FILE *fptrbin);

#endif // FONCTIONS_H_INCLUDED
