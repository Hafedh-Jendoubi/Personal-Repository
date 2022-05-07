#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    char designation[20];
    char type[20];
    int quantitedisp;
}aide;

typedef struct
{
    int CINchef;
    int nfamille;
    char delegation[20];
}famille;

void menuprincipal();
int menu(); /** Je fais deux menus pour éviter la répition de l'affichage du menu! **/
int verifier_exit( aide TA[], int nA, char designation[]);
void saisir_aide(aide *A);
void ajouter_aide(aide TA[], int *nA, aide A);

#endif // FONCTIONS_H_INCLUDED
