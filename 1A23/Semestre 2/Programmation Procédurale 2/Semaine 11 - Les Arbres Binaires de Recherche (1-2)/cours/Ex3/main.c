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

int sommeArbre(Arbre R)
{
    if(R == NULL)
        return 0;
    else
        return R->val + sommeArbre(R->FG) + sommeArbre(R->FD);
}

int main()
{
    Arbre R = NULL;

    R = AjouterNoeud(R, 5); R = AjouterNoeud(R, 4); R = AjouterNoeud(R, 6); R = AjouterNoeud(R, 3);
    printf("Somme = %d\n", sommeArbre(R));

    return 0;
}