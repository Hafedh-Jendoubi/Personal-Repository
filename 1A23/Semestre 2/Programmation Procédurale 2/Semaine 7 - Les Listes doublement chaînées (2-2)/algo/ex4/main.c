#include <stdio.h>
#include <stdlib.h>

typedef struct Cellule{
    int val;
    struct Cellule *suiv;
    struct Cellule *prec;
}cellule;

typedef struct listeDC{
    cellule *tete;
    cellule *queu;
}LDC;

void initListe(LDC *l)
{
    l->tete = NULL;
    l->queu = NULL;
}

void afficher_list(LDC l)
{
    cellule *parc=l.tete;

    while(parc!=NULL){
        printf("%d\t", parc->val);
        parc = parc->suiv;
    }
}

LDC ajout_fin(LDC l, int x)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    if(nouv == NULL)
        printf("Error!\n");
    else{
        nouv->val = x;
        nouv->suiv = NULL;
        nouv->prec = l.queu;
        if(l.tete == NULL && l.queu == NULL)
            l.tete = nouv;
        else
            l.queu->suiv = nouv;
        l.queu = nouv;
    }

    return l;
}

void echange_elements(LDC l, int p, int n) // It works
{
    cellule *parc1 = l.tete, *parc2 = l.tete;
    int k = 1, x;

    while((parc1!=NULL) && (k!=p)){
        k++;
        parc1 = parc1->suiv;
    }
    if(parc1 == NULL)
        printf("Il y'a pas de %d cellules!\n", p);
    else{
        x = parc1->val;
        k = 1;
        while((parc2!=NULL) && (k!=n)){
            k++;
            parc2 = parc2->suiv;
        }
        if(parc2 == NULL)
            printf("Il y'a pas de %d cellules!\n", n);
        else{
            parc1->val = parc2->val;
            parc2->val = x;
            printf("Echange has been done!\n");
        }
    }

}

int main()
{
    LDC l;
    int p, n;

    initListe(&l);
    l = ajout_fin(l, 1); l = ajout_fin(l, 25); l = ajout_fin(l, 34); 
    l = ajout_fin(l, 59); l = ajout_fin(l, 2); l = ajout_fin(l, 6);
    afficher_list(l);
    printf("\nTaper la pos du 1ere nombre: "); scanf("%d", &p);
    printf("Taper la pos du 2eme nombre: "); scanf("%d", &n);
    echange_elements(l, p, n);
    afficher_list(l);

    return 0;
}