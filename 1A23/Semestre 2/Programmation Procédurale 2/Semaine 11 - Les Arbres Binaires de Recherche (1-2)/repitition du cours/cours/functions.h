#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

typedef struct Noeud{
    int val;
    struct Noeud *FG;
    struct Noeud *FD;
}*Arbre;

void menu(int *ch);
Arbre AjouterNoeudABR(Arbre R, int val);
void ParcoursPrefixe(Arbre R);
void ParcoursInfixe(Arbre R);
void ParcoursPostfixe(Arbre R);

#endif // FUNCTIONS_H_INCLUDED