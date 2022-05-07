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
void remplir_employes(char filename[]);
void chercher_employe(char filename[], char prenom[]);
void afficher_employee_nenfant(char filename[], int n);
void supprimer_employee_0enfant(char filename[]);

#endif // FONCTIONS_H_INCLUDED
