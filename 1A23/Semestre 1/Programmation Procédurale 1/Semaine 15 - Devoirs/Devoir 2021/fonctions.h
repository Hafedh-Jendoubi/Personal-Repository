#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    char couleur[10];
    int quantite;
}groupe;

typedef struct
{
    int age;
    char sexe;
}categorie;

typedef struct
{
    int code;
    categorie categorie;
    int nbJ;
    groupe TabJt[20];
    float prix;
}jouet;

void menuprincipal();
int menu(); /** Je fais deux menus pour éviter la répition de l'affichage du menu! **/
int VerifierJouet(jouet TabJt[], int nbJ, int codeJt);
void SaisirJouet(jouet *jt, jouet TabJt[], int nbJ);
void AjouterJouet(jouet TabJt[], int *nbJ);
void CalculerQuantiteTotale(jouet TabJt[], int nbJ, int code, int *qtot);
void AfficherJouets(jouet TabJt[], int nbJ, int critere);
categorie JouetEnfant(jouet TabJt[], int nbJ, int codeJt);
void TrierJouets(jouet TabJt[], int nbJ);
void Initialiser(jouet MatriceJt[][30]);
void MettreEnPlaceRayon(jouet Jt, jouet MatriceJt[][30]);
void MettreEnPlaceMagasin(jouet TabJt[], int nbJ, jouet MatriceJt[][30]);

#endif // FONCTIONS_H_INCLUDED
