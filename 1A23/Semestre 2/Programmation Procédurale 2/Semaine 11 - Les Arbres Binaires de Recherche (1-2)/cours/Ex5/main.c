#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int val;
    struct Noeud *FG;
    struct Noeud *FD;
}*Arbre;

void AjouterNoeud(Arbre *R, int val)
{
    struct Noeud * nouv;
    if(*R == NULL){
        nouv = (Arbre) malloc(sizeof(struct Noeud));
        nouv->val = val;
        nouv->FD = NULL;
        nouv->FG = NULL;
        *R = nouv;
    }else{
        if(val <= (*R)->val)
            AjouterNoeud(&(*R)->FG, val);
        else
            AjouterNoeud(&(*R)->FD, val);
    }
}

int ComparerArbre(Arbre A, Arbre B)
{
    if(A == NULL)
        return (B != NULL);
    else{
        if(B == NULL)
            return 1;
        else
            return ((A->val != B->val) || ComparerArbre(A->FG, B->FG) || ComparerArbre(A->FD, B->FD));
    }
}

int main()
{
    Arbre A1=NULL, A2=NULL;
    Arbre B1=NULL, B2=NULL;

    /** A1 & A2 Sont deux Arbres Binaires Egaux **/
    AjouterNoeud(&A1, 5); AjouterNoeud(&A1, 4); AjouterNoeud(&A1, 6); AjouterNoeud(&A1, 3);
    AjouterNoeud(&A2, 5); AjouterNoeud(&A2, 4); AjouterNoeud(&A2, 6); AjouterNoeud(&A2, 3);
    printf("A1 et A2 sont egaux? La resultat est: %d ([0] Egaux - [1] Non-Egaux)\n\n", ComparerArbre(A1, A2));

    /** B1 & B2 ne sont pas deux Arbres Binaires Egaux **/
    AjouterNoeud(&B1, 5); AjouterNoeud(&B1, 4); AjouterNoeud(&B1, 6); AjouterNoeud(&B1, 3);
    AjouterNoeud(&B2, 2); AjouterNoeud(&B2, 3); AjouterNoeud(&B2, 1); AjouterNoeud(&B2, 4);
    printf("B1 et B2 sont egaux? La resultat est: %d ([0] Egaux - [1] Non-Egaux)\n\n", ComparerArbre(B1, B2));

    return 0;
}