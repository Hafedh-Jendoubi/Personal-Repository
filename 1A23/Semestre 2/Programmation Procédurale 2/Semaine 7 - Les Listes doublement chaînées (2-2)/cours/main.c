#include <stdlib.h>
#include <stdio.h>

typedef struct Cellule{
    int val;
    struct Cellule *suivant;
    struct Cellule *precedent;
}cellule;

typedef struct listeLDC{
    cellule *tete;
    cellule *queu;
}LDC;

void init_LDC(LDC *l)
{
    l->tete = NULL;
    l->queu = NULL;
}

int listeDC_vide(LDC l)
{
    if(l.tete == NULL && l.queu == NULL)
        return 1;
    else
        return 0;
}

void debut(int x, LDC l)
{
    if(x == l.tete->val)
        printf("%d est au debut de la liste!\n", x);
    else
        printf("%d n'est pas au debut de la liste!\n", x);
}

void fin(int x, LDC l)
{
    if(x == l.queu->val)
        printf("%d est a la fin de la liste!\n", x);
    else
        printf("%d n'est pas a la fin de la liste\n", x);
}

LDC ajoute_Tete(LDC l, int x)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->val = x;
    nouv->precedent = NULL;
    nouv->suivant = l.tete;
    if(listeDC_vide(l)==1) /** Cas d'une liste vide! **/
        l.queu = nouv;
    else
        l.tete->precedent = nouv;
    l.tete = nouv;

    return l;
}

LDC ajoute_Fin(LDC l, int x)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->val = x;
    nouv->suivant = NULL;
    nouv->precedent = l.queu;
    if(listeDC_vide(l)==1) /** Cas d'une liste vide! **/
        l.tete = nouv;
    else
        l.queu->suivant = nouv;
    l.queu = nouv;

    return l;
}

void parcour_LDC(LDC l)
{
    cellule *parc;

    if(listeDC_vide(l)==1)
        printf("Liste est vide!\n");
    else{
        parc = l.queu;
        while(parc!=NULL){
            printf("%d\n", parc->val);
            parc = parc->precedent;
        }
    }
}

int main()
{
    LDC l;
    int ch, x;

    init_LDC(&l);
    printf("~~~~~~ Menu: ~~~~~~\n");
    printf("1- Ajouter au debut\n");
    printf("2- Ajouter a la fin\n");
    printf("3- Check debut\n");
    printf("4- Check fin\n");
    printf("5- Parcourir la listeDC de la fin\n");
    printf("0- Exit\n");
    do{
        do{
            printf("Taper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>5));

        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                printf("Taper la valeur a ajouter: "); scanf("%d", &x);
                l = ajoute_Tete(l, x); break;

            case 2:
                printf("Taper la valeur a ajouter: "); scanf("%d", &x);
                l = ajoute_Fin(l, x); break;

            case 3:
                printf("Taper la valeur pour verifier s'il est au debut: "); scanf("%d", &x);
                debut(x, l); break;

            case 4:
                printf("Taper la valeur pour verifier s'il est a la fin: "); scanf("%d", &x);
                fin(x, l); break;

            case 5:
                parcour_LDC(l); break;
        }

    }while(ch!=0);

    return 0;
}