#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    int val;
    struct Noeud *FG;
    struct Noeud *FD;
}*Arbre;

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

void parcoursPrefixe(Arbre R, int *i)
{
    if(R!=NULL){
        (*i)++; printf("%d\n", *i);
        parcoursPrefixe(R->FG, i);
        parcoursPrefixe(R->FD, i);
    }
}

Arbre construireArbre(int racine, Arbre A, Arbre B)
{
    Arbre C;

    C = (Arbre) malloc(sizeof(struct Noeud));
    C->val = racine;
    C->FG = A;
    C->FD = B;
    
    return C;
}

int main()
{
    int a, i =0;
    Arbre A=NULL, B=NULL;

    printf("Taper la racine du nouveau arbre: "); scanf("%d", &a);
    A = AjouterNoeudABR(A, 5); A = AjouterNoeudABR(A, 4); A = AjouterNoeudABR(A, 6);
    A = AjouterNoeudABR(A, 3); A = AjouterNoeudABR(A, 7);
    parcoursPrefixe(A, &i);

    return 0;
}