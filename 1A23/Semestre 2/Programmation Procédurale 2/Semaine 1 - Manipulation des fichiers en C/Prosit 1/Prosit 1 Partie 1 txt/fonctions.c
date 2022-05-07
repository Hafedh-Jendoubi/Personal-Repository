#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("0: Exit\n");
    printf("1: Remplir les informations d'un employe dans le fichier\n");
    printf("2: Chercher le prenom de l'employe dans un fichier\n");
    printf("3: Afficher qui ont n enfants\n");
    printf("4: Supprimer tous les employes avec 0 enfants\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)||(choix>4));

    return choix;
}

void remplir_employes(char filename[])
{
    FILE *P;
    int i, n;
    employe e;

    P = fopen(filename, "w+");

    if(P != NULL){
        printf("Taper le nombre d'employes: "); scanf("%d", &n);
        for(i=0; i<n; i++){
            printf("Taper le nom du employe n%d: ", i+1); scanf("%s", e.nom);
            printf("Taper le prenom du employe n%d: ", i+1); scanf("%s", e.prenom);
            printf("Taper le nombre d'enfants du employe n%d: ", i+1); scanf("%d", &e.nbEnfant);
            fprintf(P, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, e.nbEnfant);
        }
        printf("Ajout terminee!\n");
    }else
        printf("Impossible!\n");

    fclose(P);
}

void chercher_employe(char filename[], char prenom[])
{
    FILE *P;
    employe e;
    int x = 1;

    P = fopen(filename, "r");

    if(P != NULL){
        while((!feof(P))&&(x!=0)){
            fscanf(P, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, &e.nbEnfant);
            x = strcmp(prenom, e.prenom);
        }
        if(x==0)
            printf("%s est trouve!\n", prenom);
        else
            printf("%s n'est pas trouve!\n", prenom);
    }else
        printf("Impossible!\n");

    fclose(P);
}

void afficher_employee_nenfant(char filename[], int n)
{
    FILE *P;
    employe e;
    int trv=0;

    P = fopen(filename, "r");

    if(P != NULL){
        while(!feof(P)){
            fscanf(P, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, &e.nbEnfant);
            if(e.nbEnfant==n){
                printf("%s %s\n", e.nom, e.prenom);
                trv = 1;
            }
        }
        if(trv==0)
            printf("Pas de employe ayant %d enfants!\n", n);
        fclose(P);
    }else
        printf("Impossible!\n");
}

void supprimer_employee_0enfant(char filename[])
{
    FILE *P, *fptr;
    char buffer[30] = "nombre_de_enfants.txt";
    employe e;

    P = fopen(filename, "r");
    fptr = fopen(buffer, "w");

    if(P != NULL && fptr){
        while(!feof(P)){
            fscanf(P, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, &e.nbEnfant);
            if(e.nbEnfant!=0)
                fprintf(fptr, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, e.nbEnfant);
        }
        fclose(P);
        fclose(fptr);
        remove(filename);
        rename(buffer, filename);
        printf("Employe qui ont 0 enfants ont ete supprime!\n");
    }else
        printf("Impossible!\n");
}
