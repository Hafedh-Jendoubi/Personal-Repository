#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~ Menu: ~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Ajouter un adherent\n");
    printf("2- Afficher la liste des adherents\n");
    printf("3- Ajouter un constat\n");
    printf("4- Initialiser la matrice des constats\n");
    printf("5- Afficher la liste des constats\n");
    printf("6- Rechercher un constat\n");
    printf("7- Verifier si un constat est rembourse ou non\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)&&(choix>7));

    return choix;
}

Adherant saisirAd()
{
    Adherant A;

    printf("ID: "); scanf("%d", &A.id);
    printf("Nom: "); fflush(stdin); gets(A.nom);
    printf("Prenom: "); fflush(stdin); gets(A.prenom);
    printf("Plafond de remboursement: "); scanf("%f", &A.plafond);

    return A;
}

int ajouterAdherent(Adherant ad, Adherant A[], int n)
{
    int k, trouve;

    k=0; trouve=0;
    while((k<n)&&(trouve==0)){
        if(ad.id == A[k].id){
            trouve = 1;
            printf("Adherent existe deja!\n");
        }else{
            k++;
        }
    }
    if(trouve==0){
        printf("Ajout fait avec succes!\n");
        A[n] = ad;
        n++;
    }

    return n;
}

void afficherAdherent(Adherant A[], int n)
{
    int i;

    printf("Liste des Adherents:\n");
    for(i=0; i<n; i++){
        printf("\nAdherent n%d:\n", i+1);
        printf("ID: %d\n", A[i].id);
        printf("Nom: %s\n", A[i].nom);
        printf("Prenom: %s\n", A[i].prenom);
        printf("Plafond de remboursement: %.2f\n", A[i].plafond);
    }
}

Constat saisirConstat(Adherant A[], int nA)
{
    Constat co;
    int k, trouve;

    printf("Type: ([0] Accident de voiture - [1] Incendie - [2] Vol) "); scanf("%d", &co.type);
    printf("ID d'adherent: "); scanf("%d", &co.identifiant);
    printf("Reference: "); scanf("%d", &co.reff);
    printf("Prix de remboursement: "); scanf("%f", &co.prix);

    k=0; trouve=0;
    while((k<nA)&&(trouve==0)){
        if(A[k].id == co.identifiant){
            printf("\nAdherent existe deja!\n");
            trouve = 1;
        }else{
            k++;
        }
    }
    if(trouve==0)
        printf("\nAdherent n'existe pas!\n");

    return co;
}

Constat initialiser(Constat C[2][4])
{
    int i, j;

    for(i=0; i<2; i++){
        for(j=0; j<4; j++){
            C[i][j].reff = 0;
        }
    }
    printf("Les references ont ete initialise!\n");

    return C[2][4];
}

int verification(Constat C[2][4], int a)
{
    int i=0, test=0;

    while((i<4)&&(test==0)){
        if(C[a][i].type!=a){
            test = 1;
        }else{
            i++;
        }
    }

    return i;
}

Constat ajouterConstat(Constat C[2][4], Constat co)
{
    if(verification(C, co.type)<5){
        C[co.type][verification(C,co.type)] = co;
        printf("Constat fait avec succes!\n");
    }else{
        printf("Matrice saturee!\n");
    }

    return C[2][4];
}

void afficherConstat(Constat C[2][4]) //Cette fonction n'est pas longue mais j'aime d'avoir un bon affichage.
{
    int i;

    printf("--------------------------------\nLes constats des Accidents de voitures:\n");
    for(i=0; i<verification(C, 0); i++){
        printf("Type: %d\n", C[0][i].type);
        printf("ID d'adherent: %d\n", C[0][i].identifiant);
        printf("Reference: %d\n", C[0][i].reff);
        printf("Prix de remboursement: %.2f\n\n", C[0][i].prix);
    }
    printf("--------------------------------\nLes constats des Incendies:\n");
    for(i=0; i<verification(C, 1); i++){
        printf("Type: %d\n", C[1][i].type);
        printf("ID d'adherent: %d\n", C[1][i].identifiant);
        printf("Reference: %d\n", C[1][i].reff);
        printf("Prix de remboursement: %.2f\n\n", C[1][i].prix);
    }
    printf("--------------------------------\nLes constats des Vols:\n");
    for(i=0; i<verification(C, 2); i++){
        printf("Type: %d\n", C[2][i].type);
        printf("ID d'adherent: %d\n", C[2][i].identifiant);
        printf("Reference: %d\n", C[2][i].reff);
        printf("Prix de remboursement: %.2f\n\n", C[2][i].prix);
    }
    printf("--------------------------------\n");
}

Constat chercherConstat(Constat C[2][4])
{
    int trouve=0, i, j, referee;
    Constat co;

    printf("Taper la reference: "); scanf("%d", &referee);
    for(i=0; i<2&&!(trouve); i++){
        for(j=0; j<4&&!(trouve); j++){
            if(C[i][j].reff==referee){
                trouve = 1;
                co = C[i][j];
            }
        }
    }
    if(trouve==0){
        co.reff = 0;
        printf("-1\n");
    }

    return co;
}

int verifierRemboursement(Constat C[2][4], Adherant A[], int* pnA)
{
    int referee, i, idco;
    float prixco, prixad;
    Constat co;

    co = chercherConstat(C);
    if(co.reff!=0){
        prixco = co.prix;
        idco = co.identifiant;
        for(i=0; i<*pnA; i++){
            if(A[i].id == idco){
                prixad = A[i].plafond;
            }
        }
        if(prixad>prixco)
            printf("1\n");
        else
            printf("0\n");
    }else{
        printf("Verifier la reference!\n");
    }

}

/** Still working on it **/

