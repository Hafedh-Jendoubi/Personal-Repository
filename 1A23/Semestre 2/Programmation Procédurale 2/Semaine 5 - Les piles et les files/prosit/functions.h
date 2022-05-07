#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int num;
    int priority;
}dossier;

struct cellule
{
    dossier d;
    struct cellule *suivant;
};

struct file{
    struct cellule *tete;
    struct cellule *queu;
};

typedef struct cellule *pile;
typedef struct file file;

void menuprincipal();
int menu();
/** Partie 1 **/
dossier saisir_dossier();
pile ajouter_dossier(pile p);
pile retirer_dossier(pile p);
void dernier_dossier(pile p);
pile free_pile(pile p);
pile mettrePile_dansPile(pile p, pile ap);
pile permutation(pile p);

/** Partie 2: **/
file initFile();
file deplacer(file f, pile *p);
void consulter_file(file f);
file remove_dossier(file f);

#endif // FUNCTIONS_H_INCLUDED
