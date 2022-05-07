#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Ajouter un animal\n");
    printf("2: Afficher les animaux du zoo\n");
    printf("3: Trier les animaux\n");
    printf("4: Calculer le pourcentage des animaux herbivores et le pourcentage des animaux carnivores\n");
    printf("5: Placer un animal dans une cage\n");
    printf("0: Exit\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)||(choix>5));

    return choix;
}

void verifierExistEspece(char nomE[], espece tabE[], int nE, int *pos)
{
    int k=0, trouve=0;

    while((k<nE)&&(trouve==0)){
        if(strcmp(tabE[k].nom, nomE)==0){
            (*pos) = k;
            trouve = 1;
        }else
            k++;
    }
    if(trouve==0)
        (*pos) = -1;
}

void remplirEspeces(espece tabE[], int nE)
{
    int i, pos;

    for(i=0; i<nE; i++){
        printf("Nom Espece n%d: ", i+1); scanf("%s", tabE[i].nom);
        verifierExistEspece(tabE[i].nom, tabE, nE, &pos);
        if(pos!=-1){
            do{
                printf("Regime: (carnivor - herbivor) "); scanf("%s", tabE[i].regime);
            }while((strcmp(tabE[i].regime, "carnivor")!=0)&&(strcmp(tabE[i].regime, "herbivor")!=0));
            tabE[i].nanimaux = 0;
            printf("\n");
        }else
            printf("L'espece %s existe deja!\n", tabE[pos].nom);
    }
}

void saisirAnimal(animal *a)
{
    printf("Code: "); scanf("%d", &a->code);
    printf("Poids: "); scanf("%f", &a->poids);
}

void ajouterAnimal(animal a, char nomE[], espece tabE[], int nE)
{
    int pos, x;

    verifierExistEspece(nomE, tabE, nE, &pos);
    if(pos!=-1){
        saisirAnimal(&a);
        x = tabE[pos].nanimaux;
        tabE[pos].TA[x] = a;
        x++;
    }else
        printf("Espece n'existe pas!\n");
}
