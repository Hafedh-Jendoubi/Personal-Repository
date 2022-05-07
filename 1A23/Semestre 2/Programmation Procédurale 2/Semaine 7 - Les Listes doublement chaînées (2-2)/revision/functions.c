#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Ajouter un Ordinateur dans une Liste\n");
        printf("2- Afficher la Liste des Ordinateurs\n");
        printf("3- Vendre un Ordinateur\n");
        printf("4- Enfiler les Ordinateurs en Rupture de Stock\n");
        printf("5- Approvisionner un Ordinateur\n");
        printf("0- Exit\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>4));
}

void saisirOrdinateur(ordinateur *o)
{
    printf("Marque: "); scanf("%s", o->marque);
    printf("La taille de memoire: "); scanf("%d", &o->taille);
    printf("La Quantite: "); scanf("%d", &o->quantite);
    printf("Prix: "); scanf("%f", &o->prix);
}

cellule* chercherOrdinateur(liste l, char marque[], int taille)
{
    cellule *parc=l;

    if(l==NULL)
        printf("Liste vide!\n");
    else{
        while(parc!=NULL){
            if(strcmp(marque, parc->o.marque)==0 && parc->o.taille==taille)
                break;
            parc = parc->suivant;
        }
    }

    return parc;
}

liste ajouterDebut(liste l, ordinateur o)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    if(nouv == NULL)
        printf("Error!\n");
    else{
        nouv->o = o;
        nouv->suivant = l;
        l = nouv;
    }

    return l;
}

liste ajouterOrdinateur(liste l, ordinateur o)
{
    cellule *trv=NULL;

    trv = chercherOrdinateur(l, o.marque, o.taille);
    if(trv == NULL)
        l = ajouterDebut(l, o);
    else{
        trv->o.quantite = trv->o.quantite + o.quantite;
        if(trv->o.prix < o.prix)
            trv->o.prix = o.prix;
    }
    printf("Ordinateur ajoute avec succes!\n");

    return l;
}

void afficherListe(liste l, char nomFichier[])
{
    FILE *f=NULL;
    cellule *parc;

    if(l==NULL)
        printf("Liste est vide!\n");
    else{
        f = fopen(nomFichier, "w+");
        if(f == NULL)
            printf("Error!\n");
        else{
            parc = l;
            while(parc != NULL){
                printf("Marque: %s  Taille: %d  Quantite: %d  Prix: %.3f\n", parc->o.marque, parc->o.taille, parc->o.quantite, parc->o.prix);
                fprintf(f, "Marque: %s  Taille: %d  Quantite: %d  Prix: %.3f\n", parc->o.marque, parc->o.taille, parc->o.quantite, parc->o.prix);
                parc = parc->suivant;
            }
        }
        fclose(f);
    }
}

void initFile(file *f)
{
    f->queue = NULL;
    f->tete = NULL;
}

file enfilerOrdinateur(file f, ordinateur o)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    if(nouv == NULL)
        printf("Error!\n");
    else{
        nouv->o = o;
        nouv->suivant = NULL;
        if(f.tete==NULL && f.queue==NULL) //Cas d'une File Vide
            f.tete = nouv;
        else
            f.queue->suivant = nouv;
        f.queue = nouv;
    }

    return f; 
}

void vendreCaracteristique(ordinateur *o)
{
    printf("Marque: "); scanf("%s", o->marque);
    printf("Taille: "); scanf("%d", &o->taille);
    printf("Quantite: "); scanf("%d", &o->quantite);
}

void vendreOrdinateur(liste l, char marque[], int taille, int qte)
{
    cellule *trv=NULL;

    trv = chercherOrdinateur(l, marque, taille);
    if(trv == NULL)
        printf("Ordinateur n'existe pas\n");
    else{
        if(trv->o.quantite < qte)
            printf("Erreur! (Quantite existante inferieur a celle vous vouler vendre)\n");
        else{
            trv->o.quantite = trv->o.quantite - qte;
            printf("Ordinateur vendu avec succes!\n");
        }
    }
}

file enfilerRuptureStock(liste l, file f)
{
    cellule *parc;

    if(l==NULL)
        printf("Liste est vide!\n");
    else{
        parc = l;
        while(parc!=NULL){
            if(parc->o.quantite == 0)
                f = enfilerOrdinateur(f, parc->o);
            parc = parc->suivant;
        }
        printf("Done!\n");
    }

    return f;
}

file approvisionnerOrdinateur(liste l, file f)
{
    
}