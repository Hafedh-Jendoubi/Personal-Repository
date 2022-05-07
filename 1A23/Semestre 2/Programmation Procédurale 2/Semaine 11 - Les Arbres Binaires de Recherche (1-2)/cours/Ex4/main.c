#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int val;
    struct Noeud *FG;
    struct Noeud *FD;
}*Arbre;

Arbre AjouterNoeud(Arbre R, int val)
{
    struct Noeud *nouv;

    if(R == NULL){
        nouv = (Arbre)malloc(sizeof(struct Noeud));
        nouv->val = val;
        nouv->FD = NULL;
        nouv->FG = NULL;
        R = nouv;
    }else{
        if(val <= R->val)
            R->FG = AjouterNoeud(R->FG, val);
        else
            R->FD = AjouterNoeud(R->FD, val);
    }

    return R;
}

int Recherche(Arbre R, int x)
{
    if(R!=NULL){
        if(R->val == x)
            return 1;
        else
            return Recherche(R->FG, x) + Recherche(R->FD, x);
    }
}

int main()
{
    Arbre R = NULL;

    R = AjouterNoeud(R, 5); R = AjouterNoeud(R, 4); R = AjouterNoeud(R, 6); R = AjouterNoeud(R, 3);  R = AjouterNoeud(R, 7); R = AjouterNoeud(R, 2); R = AjouterNoeud(R, 8);
    printf("1 n'existe pas dans ce arbre alors la resultat est: %d\n", Recherche(R, 1));
    printf("2 existe dans ce arbre alors la resultat est: %d\n", Recherche(R, 2));

    return 0;
}