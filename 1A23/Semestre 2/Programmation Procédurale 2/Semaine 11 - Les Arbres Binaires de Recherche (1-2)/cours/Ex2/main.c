#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int val;
    struct Noeud *FG;
    struct Noeud *FD;
}*Arbre;

Arbre AjouterNoeud(Arbre R, int val)
{
    struct Noeud *nouv=NULL;

    if(R == NULL){
        nouv = (Arbre) malloc(sizeof(struct Noeud));
        nouv->val = val;
        nouv->FG = NULL;
        nouv->FD = NULL;
        R = nouv;
    }else{
        if(val <= R->val)
            R->FG = AjouterNoeud(R->FG, val);
        else
            R->FD = AjouterNoeud(R->FD, val);
    }

    return R;
}

void affichageCroissant(Arbre R)
{
    if(R!=NULL){
        affichageCroissant(R->FG);
        printf("%d\n", R->val);
        affichageCroissant(R->FD);
    }
}

int main()
{
    Arbre R=NULL;

    R = AjouterNoeud(R, 5); R = AjouterNoeud(R, 4); R = AjouterNoeud(R, 3); R = AjouterNoeud(R, 2);
    R = AjouterNoeud(R, 1); R = AjouterNoeud(R, 6); R = AjouterNoeud(R, 7); R = AjouterNoeud(R, 8);
    affichageCroissant(R);

    return 0;
}