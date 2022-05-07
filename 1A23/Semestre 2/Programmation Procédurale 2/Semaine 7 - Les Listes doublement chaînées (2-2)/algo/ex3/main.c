#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float moy;
}etudiant;

typedef struct Cellule{
    etudiant e;
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
        printf("%.2f\t", parc->e.moy);
        parc = parc->suiv;
    }
}

void afficher_list_back(LDC l) // It works
{
    cellule *parc=l.queu;

    while(parc!=NULL){
        printf("%.2f\t", parc->e.moy);
        parc = parc->prec;
    }
}

LDC ajouter_debut(LDC l, float x)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    if(nouv == NULL)
        printf("Memory Struggle, (add_tail() function)\n");
    else{
        nouv->e.moy = x;
        nouv->suiv = l.tete;
        nouv->prec = NULL;
        if(l.tete == NULL && l.queu == NULL)
            l.queu = nouv;
        else
            l.tete->prec = nouv;
        l.tete = nouv;
    }

    return l;
}

LDC ajout_fin(LDC l, float x)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    if(nouv == NULL)
        printf("Error!\n");
    else{
        nouv->e.moy = x;
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

void ajout_dans(LDC *l, float x) // It works
{
    cellule *nouv, *parc=l->tete;

    while((parc->suiv!=NULL) && (x>parc->e.moy))
        parc = parc->suiv;

    if(parc == l->queu)
        *l = ajout_fin(*l, x);
    else if(parc == l->tete)
        *l = ajouter_debut(*l, x);
    else{
        nouv = (cellule*) malloc(sizeof(cellule));
        nouv->e.moy = x;
        if(nouv == NULL)
            printf("Memory Struggle!\n");
        else{
            nouv->suiv = parc;
            nouv->prec = parc->prec;
            parc->prec->suiv = nouv;
            parc->prec = nouv;
        }
    }
}

void afficher_inf_10(LDC l)
{
    cellule *parc;

    if(l.tete == NULL)
        printf("Liste vide!\n");
    else{
        parc = l.tete;
        while(parc != NULL){
            if(parc->e.moy >= 10)
                printf("%.2f", parc->e.moy);
            parc = parc->suiv;
        }
    }
}

int main()
{
    LDC l;

    initListe(&l);
    l = ajout_fin(l, 5); l = ajout_fin(l, 13); l = ajout_fin(l, 17);  l = ajout_fin(l, 6); l = ajout_fin(l, 17);
    afficher_inf_10(l);
    

    return 0;
}