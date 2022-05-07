#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Inserer dans une Arbre\n");
        printf("2- Affichage Prefixe\n");
        printf("3- Affichage Infixe\n");
        printf("4- Affichage Postfixe\n");
        printf("0- Exit\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>4));
}

Arbre AjouterNoeudABR(Arbre R, int val)
{
    struct Noeud * nouv;
    if(R == NULL){
        nouv = (struct Noeud*) malloc(sizeof(struct Noeud));
        if(nouv == NULL)
            printf("Memory struggle!\n");
        else{
            nouv->val = val;
            nouv->FD = NULL;
            nouv->FG = NULL;
            R = nouv;
        }
    }else{
        if(val <= R->val)
            R->FG = AjouterNoeudABR(R->FG, val);
        else
            R->FD = AjouterNoeudABR(R->FD, val);
    }

    return R;
}

void ParcoursPrefixe(Arbre R)
{
    if(R != NULL){
        printf("Racine = %d\n", R->val);
        ParcoursPrefixe(R->FG);
        ParcoursPrefixe(R->FD);
    }
}

void ParcoursInfixe(Arbre R)
{
    if(R != NULL){
        ParcoursInfixe(R->FG);
        printf("Racine = %d\n", R->val);
        ParcoursInfixe(R->FD);
    }
}

void ParcoursPostfixe(Arbre R)
{
    if(R != NULL){
        ParcoursPostfixe(R->FG);
        ParcoursPostfixe(R->FD);
        printf("Racine = %d\n", R->val);
    }
}