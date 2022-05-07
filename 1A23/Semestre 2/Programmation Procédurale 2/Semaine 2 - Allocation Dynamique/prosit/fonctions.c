#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

void MenuDisplay()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Test program (Only programmers)\n");
    printf("2: Ajouter un voyageur\n");
    printf("3: Supprimer un voyageur\n");
    printf("0: Sauvegarder && Exit\n");
}

void Choice(int *choix)
{
    do{
        printf("\nTaper votre choix: "); scanf("%d", &(*choix));
    }while((*choix<0)||(*choix>3));
}

int nbVoyageurs(char nomFich[])
{
    FILE *f;
    int n=0;
    voyageur v;

    f = fopen(nomFich, "rb");
    if(f==NULL)
        printf("EROR: Memory issue! (Calculating Travelers Number Function)\n");
    else
    {
        while(fread(&v, sizeof(voyageur), 1, f))
            n++;
    }
    fclose(f);

    return n;
}

void saisirVoyageur(voyageur *ptv)
{
    printf("ID: "); scanf("%s", ptv->id);
    printf("Nom: "); scanf("%s", ptv->nom);
    printf("Adresse: "); scanf("%s", ptv->adresse);
    printf("Nombre total des voyages: "); scanf("%d", &ptv->nb_voyage);
}

voyageur* charger_donnees(char nomFich[], int *n)
{
    FILE *f;
    int k=0;
    voyageur v, *tab;

    (*n) = nbVoyageurs(nomFich);
    f = fopen(nomFich, "rb");
    if(f==NULL)
        printf("EROR: Memory issue! (Loading Data Function)\n");
    else
    {
        tab = (voyageur*) malloc(((*n)+1)*sizeof(voyageur));
        if(tab==NULL)
            printf("EROR: Memory issue! (Malloc in Loading Data Function)\n");
        else{
            while(k<(*n)){
                fread(&v, sizeof(voyageur), 1, f);
                tab[k] = v;
                k++;
            }
        }
    }
    fclose(f);

    return tab;
}

void DisplayLoadingData(char nomFich[])
{
    int i;
    FILE *f;

    f=fopen(nomFich, "ab");
    if(f==NULL)
        printf("EROR: Memory struggle! (DislpayLoadingData Function)\n");
    else{
        printf("Loading File Data");
        for(i=3; i>0; i--){
            printf(".");
            sleep(1);
        }
        printf("\nFile has been succefully loaded!\n"); sleep(2); system("cls");
    }
    fclose(f);
}

void tester(voyageur *tab, int n)
{
    int i;

    if(n==0)
        printf("Pas de voyageurs!\n");
    for(i=0; i<n; i++){
        printf("ID: %s  Nom: %s  Adresse: %s  Nombre de voyages: %d\n", tab[i].id, tab[i].nom, tab[i].adresse, tab[i].nb_voyage);
    }
}

void sauvegarder_donnees(char nomFich[], voyageur *tab, int n)
{
    FILE *f;
    int k=0;

    f = fopen(nomFich, "w+b");
    if(f==NULL)
        printf("EROR: Memory issue! (Saving Data Function)\n");
    else
    {
        while(k<n){
            fwrite(&tab[k], sizeof(voyageur), 1, f);
            k++;
        }
        printf("File has been saved succefully!\n");
    }
    fclose(f);
}

int trouver(voyageur *tab, char id[], int n)
{
    int k=0, trv=0;

    while((k<n)&&(trv==0)){
        if(strcmp(tab[k].id, id)==0)
            trv = 1;
        else
            k++;
    }

    if(trv==0)
        k = -1;

    return k;
}

voyageur* ajouter(voyageur v, voyageur *tab, int *n)
{
    int pos;

    pos = trouver(tab, v.id, (*n));
    if(pos==-1){
        tab = (voyageur*) realloc(tab, ((*n)+1)*sizeof(voyageur));
        if(tab==NULL)
            printf("EROR: Memory issue! (Realloc in Adding a Traveler Function)\n");
        else{
            tab[(*n)] = v;
            printf("Voyageur ajoute avec succes!\n");
            (*n)++;
        }
    }else{
        tab[pos].nb_voyage = tab[pos].nb_voyage + v.nb_voyage;
        printf("Voyageur existe deja, son nombre de voyage total a ete incrimente!\n");
    }

    return tab;
}

void supprimer(voyageur *tab , char id[], int *n)
{
    int pos, i;

    pos = trouver(tab, id, (*n));
    if(pos==-1)
        printf("Voyageur inexistant!\n");
    else{
        for(i=pos; i<(*n)-1; i++)
            tab[i] = tab[i+1];
        tab = (voyageur*) realloc(tab, (*n)*sizeof(voyageur));
        if(tab==NULL)
            printf("EROR: Memory struggle! (Realloc in Delete Function)\n");
        else
        {
            (*n)--;
            printf("Voyageur a ete supprime!\n");
        }
    }
}

void liberer(voyageur *tab)
{
    free(tab);
}
