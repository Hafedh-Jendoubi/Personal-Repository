#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

typedef struct
{
    int code;
    float poids;
}animal;

typedef struct
{
    char nom[20];
    char regime[10];
    int nanimaux;
    animal TA[50];
}espece;

void menuprincipal();
int menu(); /** Je fais deux menus pour éviter la répition de l'affichage du menu! **/
void verifierExistEspece(char nomE[], espece tabE[], int nE, int *pos);
void remplirEspeces(espece tabE[], int nE);
void saisirAnimal(animal *a);
void ajouterAnimal(animal a, char nomE[], espece tabE[], int nE);

#endif // FONCTIONS_H_INCLUDED
