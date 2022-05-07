#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Ajouter une station\n");
        printf("2- Afficher le chemin de la competition\n");
        printf("3- Inistialiser la competition\n");
        printf("0- Quitter\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>3));
}

void initchemin(LDC *l)
{
    l->tete = NULL;
    l->queu = NULL;
}

station saisir_station()
{
    station s;
    int i;

    do{
        printf("Numero de la station: "); scanf("%d", &s.num);
    }while(s.num<1);
    printf("La distance qui la separe de la station precedente: "); scanf("%f", &s.dist);
    for(i=0; i<3; i++){
        strcpy(s.A[i].id, "-1");
        s.A[i].h1.h = -1;
        s.A[i].h1.m = -1;
        s.A[i].h1.s = -1;
        s.A[i].h2.h = -1;
        s.A[i].h2.m = -1;
        s.A[i].h2.s = -1;
    }

    return s;
}

int liste_vide(LDC l)
{
    if(l.tete == NULL && l.queu == NULL)
        return 1;
    else
        return 0;
}

cellule* chercher_station(LDC l, int num)
{
    cellule *parc=l.tete;

    if(liste_vide(l)==1) /** Case: Empty List **/
        parc = NULL;
    else{
        while(parc!=NULL){
            if(parc->s.num == num)
                break;
            parc = parc->suiv;
        }
    }

    return parc;
}

LDC ajouter_debut(LDC l, station s)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->s = s;
    nouv->suiv = l.tete;
    nouv->prec = NULL;
    if(liste_vide(l)==1)
        l.queu = nouv;
    else
        l.tete->prec = nouv;
    l.tete = nouv;

    return l;
}

LDC ajouter_fin(LDC l, station s)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->s = s;
    nouv->suiv = NULL;
    nouv->prec = l.queu;
    if(liste_vide(l)==1)
        l.tete = nouv;
    else
        l.queu->suiv = nouv;
    l.queu = nouv;

    return l;
}

LDC ajouter_station(LDC l)
{
    station s;
    cellule *trv, *nouv;

    s = saisir_station();
    trv = chercher_station(l, s.num);
    if(trv != NULL)
        printf("Station existe deja!\n");
    else{
        nouv = (cellule*) malloc(sizeof(cellule));
        nouv->s = s;
        if(liste_vide(l)==1){
            l = ajouter_debut(l, s);
        }else{
            if(l.tete->s.num > nouv->s.num)
                l = ajouter_debut(l, s);
            else if(l.queu->s.num < nouv->s.num)
                l = ajouter_fin(l, s);
            else{
                trv = l.tete;
                while(trv->s.num < nouv->s.num)
                    trv = trv->suiv;
                nouv->suiv = trv;
                nouv->prec = trv->prec;
                trv->prec = nouv;
                nouv->prec->suiv = nouv;
            }
        }
        printf("Station ajoute avec succes!\n");
    }

    return l;
}

void Afficher_Chemin(LDC l)
{ 
    cellule *p;

    if(liste_vide(l) == 1)
        printf("Pas de stations!\n");
    else{
        p = l.queu;
        printf("*** Chemin: ***\n");
        while(p){
            printf("Station %d\n", p->s.num);
            if(p->prec != NULL)
                printf("   |^\n   ||\n");
            p = p->prec;
        }
    }
}

void initialiser_alpiniste(alpiniste *a)
{
    printf("L'ID de l'alpiniste: "); scanf("%s", a->id);
    a->h1.h = 8;
    a->h1.m = 0;
    a->h1.s = 0;
    printf("Termine avec succes!\n\n");
}

LDC init_competition(LDC l)
{
    int i;
    alpiniste a[3];

    for(i=0; i<3; i++){
        printf("Alpiniste n%d:\n", i+1);
        initialiser_alpiniste(a+i);
    }
    
    l.tete->s.A[0] = a[0];
    l.tete->s.A[1] = a[1];
    l.tete->s.A[2] = a[2];

    return l;
}