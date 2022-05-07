#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    char designation[20];
    int quantite;
    float prix;
}ingredient;

typedef struct
{
    int type;
    int ningredient;
    ingredient TI[20];
}gateau;

void menuprincipal();
int menu(); /** Je fais deux menus pour éviter la répition de l'affichage du menu! **/
void saisir(gateau *g);
void ajouterGateau(gateau tabG[], gateau g, int *tg);
void afficher(gateau tabG[], int tg);
void trouver(gateau tabG[], int tg, int type, int *pos);
float calculerPrix(gateau g);
void initialiser(int matV[3][7], float tabP[]);
void vendre(int matV[3][7], gateau tabG[], int type, int jour, int *tg, float tabP[]);

#endif // FONCTIONS_H_INCLUDED
