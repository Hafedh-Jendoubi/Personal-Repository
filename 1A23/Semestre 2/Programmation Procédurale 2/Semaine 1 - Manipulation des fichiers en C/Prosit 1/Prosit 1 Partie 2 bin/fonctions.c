#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("0: Exit\n");
    printf("1: Remplir les informations d'un employe dans le fichier binaire\n");
    printf("2: Chercher le prenom de l'employe dans un fichier binaire\n");
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

void remplir_employes(FILE *Pbin)
{
    int i, n;
    employe e;

    Pbin = fopen("nombre_enfants.bin", "w+b");

    if(Pbin != NULL){
        printf("Taper le nombre d'employes: "); scanf("%d", &n);
        for(i=0; i<n; i++){
            printf("Taper le nom du employe n%d: ", i+1); scanf("%s", e.nom);
            printf("Taper le prenom du employe n%d: ", i+1); scanf("%s", e.prenom);
            printf("Taper le nombre d'enfants du employe n%d: ", i+1); scanf("%d", &e.nbEnfant);
            fprintf(Pbin, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, e.nbEnfant);
        }
        printf("Ajout terminee!\n");
        fclose(Pbin);
    }else
        printf("Impossible!\n");
}

void chercher_employe(FILE *Pbin, char prenom[])
{
    employe e;
    int x = 1;

    Pbin = fopen("nombre_enfants.bin", "rb");

    if(Pbin != NULL){
        while((!feof(Pbin))&&(x!=0)){
            fscanf(Pbin, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, &e.nbEnfant);
            x = strcmp(prenom, e.prenom);
        }
        if(x==0)
            printf("%s est trouve!\n", prenom);
        else
            printf("%s n'est pas trouve!\n", prenom);
        fclose(Pbin);
    }else
        printf("Impossible!\n");
}

void afficher_employee_nenfant(FILE *Pbin, int n)
{
    employe e;
    int trv=0;

    Pbin = fopen("nombre_enfants.bin", "rb");

    if(Pbin != NULL){
        while(!feof(Pbin)){
            fscanf(Pbin, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, &e.nbEnfant);
            if(e.nbEnfant==n){
                printf("%s %s\n", e.nom, e.prenom);
                trv = 1;
            }
        }
        if(trv==0)
            printf("Pas de employe ayant %d enfants!\n", n);
        fclose(Pbin);
    }else
        printf("Impossible!\n");
}

void supprimer_employee_0enfant(FILE *Pbin, FILE *fptrbin)
{
    employe e;

    Pbin = fopen("nombre_enfants.bin", "rb");
    fptrbin = fopen("nombre_de_enfants.bin", "wb");

    if((Pbin != NULL)&&(fptrbin != NULL)){
        while(!feof(Pbin)){
            fscanf(Pbin, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, &e.nbEnfant);
            if(e.nbEnfant!=0)
                fprintf(fptrbin, "Nom: %s\tPrenom: %s\tNombre d'Enfants: %d\n", e.nom, e.prenom, e.nbEnfant);
        }
        printf("Employe qui ont 0 enfants ont ete supprime!\n");
        fclose(Pbin);
        fclose(fptrbin);
        remove("nombre_enfants.bin");
        rename("nombre_de_enfants.bin", "nombre_enfants.bin");
    }else
        printf("Impossible!\n");
}
