#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Ajouter un gateau dans un tableau\n");
    printf("2- Afficher tous les gateaux\n");
    printf("3- Chercher le premier gateau de type donne\n");
    printf("4- Vendre le premier gateau\n");
    printf("5- Afficher la recette d'un jour donne\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)||(choix>5));

    return choix;
}

void saisir(gateau *g)
{
    int i;

    do{
        printf("Type: ([0] chocolat - [1] nougatine - [2] pistache) "); scanf("%d", &(*g).type);
    }while(((*g).type<0)||((*g).type>2));
    printf("Nombre d'ingredient: "); scanf("%d", &g->ningredient);
    for(i=0; i<(*g).ningredient; i++){
        printf("\nIngredient n%d:\n", i+1);
        printf("Designation: "); fflush(stdin); gets(g->TI[i].designation);
        printf("Quantite: "); scanf("%d", &g->TI[i].quantite);
        printf("Prix: "); scanf("%f", &g->TI[i].prix);
    }
}

void ajouterGateau(gateau tabG[], gateau g, int *tg)
{
    tabG[(*tg)] = g;
    (*tg)++;
    printf("Gateau ajoutee avec succes!\n");
}

void afficher(gateau tabG[], int tg)
{
    int i, j;

    printf("Liste des Gateaux:\n--------------------\n");
    for(i=0; i<tg; i++){
        printf("\nGateau n%d:\n", i+1);
        printf("Type: %d\n", tabG[i].type);
        printf("Nombre d'ingredient: %d\n", tabG[i].ningredient);
        for(j=0; j<tabG[i].ningredient; j++){
            printf("\nIngredient n%d:\n", j+1);
            printf("Designation: "); puts(tabG[i].TI[j].designation);
            printf("Quantite: %d\n", tabG[i].TI[j].quantite);
            printf("Prix: %.2f TND\n", tabG[i].TI[j].prix);
        }
        printf("\n--------------------\n");
    }
}

void trouver(gateau tabG[], int tg, int type, int *pos)
{
    int i=0;

    while((i<tg)&&(tabG[i].type != type))
        i++;
    if(i<tg)
        *pos = i+1;
    else
        *pos = -1;
}

float calculerPrix(gateau g)
{
    int i;
    float cout=0, prix;

    for(i=0; i<g.ningredient; i++){
        cout = cout + (g.TI[i].prix * g.TI[i].quantite);
    }
    switch(g.type){
        case 0: prix = 1.1*cout; break;
        case 1: prix = 1.15*cout; break;
        case 2: prix = 1.2*cout; break;
    }

    return prix;
}

void initialiser(int matV[3][7], float tabP[])
{
    int i, j;

    for(i=0; i<3; i++)
        for(j=0; j<7; j++)
            matV[i][j] = 0;

    for(i=0; i<7; i++)
        tabP[i] = 0;
}

void vendre(int matV[3][7], gateau tabG[], int type, int jour, int *tg, float tabP[])
{

}
