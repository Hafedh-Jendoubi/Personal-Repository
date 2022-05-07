#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("0- Exit\n");
        printf("1- Inserer un etudiant\n");
        printf("2- Afficher Arbre\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>2));
}

abr initialiser(etudiant e)
{
    abr a;

    a->e = e;
    a->FG = NULL;
    a->FD = NULL;
}

void taper_etudiant(etudiant *e)
{
    printf("ID: "); scanf("%d", &e->id);
    printf("Nom: "); scanf("%s", e->nom);
    printf("Prenom: "); scanf("%s", e->prenom);
    do{
        printf("Niveau: "); scanf("%d", &e->niveau);
    }while((e->niveau<1)||(e->niveau>5));
    printf("Moyenne: "); scanf("%f", &e->moy);
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
            a->FG = inserer(a->FG, e);
        else
            a->FD = inserer(a->FD, e);
    }

    return a;
}

abr construireArbre(abr a, char nomFich[])
{
    
}

void afficher(abr a)
{
    if(a != NULL)
    {
        printf("\n ID = %d", a->e.id);
        printf("\n Nom: %s", a->e.nom);
        printf("\n Prenom: %s", a->e.prenom);
        printf("\n Niveau: %d", a->e.niveau);
        printf("\n Moyenne: %.2f", a->e.moy);
        afficher(a->FG);
        afficher(a->FD);
    }
}

int calculerNombre(abr a)
{
    
}