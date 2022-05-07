#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("0- Exit\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>1));
}

abr initialiser(etudiant e)
{
    abr a;

    a->e = e;
    a->FG = NULL;
    a->FD = NULL;
}

abr inserer(abr a, etudiant e)
{
    struct Noeud * nouv;

    if(a == NULL){
        nouv = (struct Noeud*) malloc(sizeof(struct Noeud));
        nouv->e = e;
        nouv->FG = NULL;
        nouv->FD = NULL;

        a = nouv;
    }else{
        if(e.moy <= a->e.moy)
            inserer(a->FG, e);
        else
            inserer(a->FD, e);
    }
}
