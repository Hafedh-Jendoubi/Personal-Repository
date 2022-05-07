#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Club.h"

int chercher_club(club TabC[], int nbC, char Mat[])
{
    int k=0, trouve=0;

    while((k<nbC)&&(trouve==0)){
        if(strcmp(TabC[k].Mat, Mat)==0)
            trouve = 1;
        else
            k++;
    }
    if(trouve==0)
        k = -1;

    return k;
}

void creer_club(club *C, club TabC[], int nbC)
{
    int pos;

    printf("Matricule: "); scanf("%s", C->Mat);
    pos = chercher_club(TabC, nbC, C->Mat);
    if(pos==-1){
        printf("Type: "); scanf("%s", C->type);
        C->nadherent = 0;
        TabC[nbC] = *C;
        printf("Club ajoute avec succes!\n");
    }else
        printf("Club deja existe!\n");
}

void ajouter_club(club TabC[], int *nbC, club C)
{
    creer_club(&C, TabC, (*nbC));
    if(C.nadherent==0)
        (*nbC)++;
}

void afficher_clubs(club TabC[], int nbC)
{
    int i;

    for(i=0; i<nbC; i++){
        printf("Club n%d: \n", i+1);
        printf("Matricule: %s\n", TabC[i].Mat);
        printf("Type: %s\n\n", TabC[i].type);
    }
}

void saisir_adherent(adherent *A)
{
    printf("Identifiant: "); scanf("%d", &A->identifiant);
    printf("Niveau: "); scanf("%s", A->niveau);
}

void Inscrire_Adherent(club TabC[], int nbC, char Mat[], adherent A)
{
    int pos;

    pos = chercher_club(TabC, nbC, Mat);
    if(pos!=-1){
        if(TabC[pos].nadherent<30){
            saisir_adherent(&A);
            TabC[pos].TabA[TabC[pos].nadherent] = A;
            TabC[pos].nadherent++;
            printf("Adherent ajoutee avec succes!\n");
        }else
            printf("Impossible, nombre adherents est 30\n");
    }else
        printf("Club inexistant!\n");
}

