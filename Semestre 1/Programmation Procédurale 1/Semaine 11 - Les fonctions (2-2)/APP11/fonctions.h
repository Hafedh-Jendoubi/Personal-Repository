#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    int id;
    char nom[30];
    char prenom[30];
    float plafond;
}Adherant;

typedef struct
{
    int type;
    int identifiant;
    int reff;
    float prix;
}Constat;

void menuprincipal();
int menu();
Adherant saisirAd();
int ajouterAdherent(Adherant ad, Adherant A[], int n);
void afficherAdherent(Adherant A[], int n);
Constat saisirConstat(Adherant A[], int nA);
Constat initialiser(Constat C[2][4]);
int verification(Constat C[2][4], int a);
Constat ajouterConstat(Constat C[2][4], Constat co);
void afficherConstat(Constat C[2][4]);
Constat chercherConstat(Constat C[2][4]);
int verifierRemboursement(Constat C[2][4], Adherant A[], int* pnA);
/** Still working on it **/

#endif // FONCTIONS_H_INCLUDED
