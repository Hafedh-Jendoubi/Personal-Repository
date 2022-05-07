#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct{
    int num;
    int type;
    int etat;
}wagon;

typedef struct cellule cellule;

struct cellule{
    wagon w;
    cellule *suivant;
};

typedef cellule *liste;

void menuprincipal();
int menu();
wagon saisirWagon(wagon w);
wagon saisirLocomotive(wagon w);
liste ajouterLocomotive(liste l, wagon w);
liste ajouterWagon(liste l, wagon w);
int longeurTrain(liste l);
int rechercherWagon(liste l, int num);
void afficherTrain(liste l);
/**          Partie 2         **/
liste supprimer_deb(liste l);
liste SupprimerWagonPanne(liste l);
liste liberer(liste l);

#endif // FONCTIONS_H_INCLUDED
