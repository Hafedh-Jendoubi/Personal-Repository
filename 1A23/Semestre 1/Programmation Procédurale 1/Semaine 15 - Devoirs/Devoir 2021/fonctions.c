#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Ajouter un jouet\n");
    printf("2: Afficher la liste des jouets\n");
    printf("3: Afficher la categorie d'enfant ciblee pour un jouet donnee par son code\n");
    printf("4: Trier par odre croissant les jouets en fonction de leur prix\n");
    printf("5: Mettre en place les jouets par tranche d'age et sexe de l'enfant\n");
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

int sousmenu()
{
    int critere;

    printf("~~ Menu: ~~\n");
    printf("\t1: Sans Critere\n");
    printf("\t2: Les jouets pour fille\n");
    printf("\t3: Les jouets pour garcon\n");
    printf("\t4: Les jouets dont le prix est inferieur a 100 DT\n");

    printf("Quelle choix voulez vous choisir: "); scanf("%d", &critere);

    return critere;
}

int VerifierJouet(jouet TabJt[], int nbJ, int codeJt)
{
    int trouve=0, k=0;

    while((k<nbJ)&&(trouve==0)){
        if(TabJt[k].code == codeJt)
            trouve = 1;
        else
            k++;
    }
    if(trouve==0)
        k = -1;

    return k;
}

void SaisirJouet(jouet *jt, jouet TabJt[], int nbJ)
{
    int i;

    printf("Taper code: "); scanf("%d", &jt->code);
    if(VerifierJouet(TabJt, nbJ, jt->code)==-1){
        do{
            printf("L'age: (0-6 ans) "); scanf("%d", &jt->categorie.age);
        }while((&jt->categorie.age<=0)&&(&jt->categorie.age>=6));
        do{
            printf("Sexe: ([F] Fille - [G] Garcon - [U] Unisex) "); fflush(stdin); scanf("%c", &jt->categorie.sexe);
        }while((jt->categorie.sexe!='F')&&(jt->categorie.sexe!='G')&&(jt->categorie.sexe!='U'));
        printf("Taper le nombre de groupe par jouet: "); scanf("%d", &jt->nbJ);
        for(i=0; i<jt->nbJ; i++){
            do{
                printf("Couleur: n%d: (Rouge - Vert - Jaune - Bleu) ", i+1); scanf("%s", jt->TabJt[i].couleur);
            }while((strcmp(jt->TabJt[i].couleur, "Jaune")!=0)&&(strcmp(jt->TabJt[i].couleur, "Vert")!=0)&&(strcmp(jt->TabJt[i].couleur, "Rouge")!=0)&&(strcmp(jt->TabJt[i].couleur, "Bleu")!=0));
            printf("Quantite n%d: ", i+1); scanf("%d", &jt->TabJt[i].quantite);
        }
        printf("Prix: "); scanf("%f", &jt->prix);
    }else
        printf("Code existe deja! Verifier votre code!\n");
}

void AjouterJouet(jouet TabJt[], int *nbJ)
{
    jouet jt;

    SaisirJouet(&jt, TabJt, (*nbJ));
    if(VerifierJouet(TabJt, (*nbJ), jt.code)==-1){
        TabJt[(*nbJ)] = jt;
        (*nbJ)++;
        printf("Jouet ajoutee avec succes!\n");
    }
}

void CalculerQuantiteTotale(jouet TabJt[], int nbJ, int code, int *qtot)
{
    int x, i;

    x = VerifierJouet(TabJt, nbJ, code);
    for(i=0; i<TabJt[x].nbJ; i++)
        (*qtot) = (*qtot) + TabJt[x].TabJt[i].quantite;
}

void AfficherJouets(jouet TabJt[], int nbJ, int critere)
{
    int i, j, k=1, qtot;

    switch(critere){
        case 1:
            for(i=0; i<nbJ; i++){
                printf("------------------\n");
                qtot = 0;
                CalculerQuantiteTotale(TabJt, nbJ, TabJt[i].code, &qtot);
                printf("Jouet n%d: \n", k);
                printf("Quantite Total: %d\n", qtot);
                printf("Code: %d\n", TabJt[i].code);
                printf("Age: %d\n", TabJt[i].categorie.age);
                printf("Sexe: %c\n", TabJt[i].categorie.sexe);
                printf("Nombre de groupe de jouet: %d\n", TabJt[i].nbJ);
                for(j=0; j<TabJt[i].nbJ; j++){
                    printf("// Groupe n%d:\n", j+1);
                    printf("\tCouleur: %s\n", TabJt[i].TabJt[j].couleur);
                    printf("\tQuantite: %d\n", TabJt[i].TabJt[j].quantite);
                }
                printf("Prix: %.2f DT\n", TabJt[i].prix);
                k++;
                printf("------------------\n\n");
            }if(k==1)
                printf("Pas de jouets pour le moment!\n");
            break;

        case 2:
            for(i=0; i<nbJ; i++){
                if(TabJt[i].categorie.sexe == 'F'){
                    qtot = 0;
                    CalculerQuantiteTotale(TabJt, nbJ, TabJt[i].code, &qtot);
                    printf("Jouet n%d: \n", i+1);
                    printf("Quantite Total: %d\n", qtot);
                    printf("Code: %d\n", TabJt[i].code);
                    printf("Age: %d\n", TabJt[i].categorie.age);
                    printf("Sexe: %c\n", TabJt[i].categorie.sexe);
                    printf("Nombre de groupe de jouet: %d\n", TabJt[i].nbJ);
                    for(j=0; j<TabJt[i].nbJ; j++){
                        printf("// Groupe n%d:\n", j+1);
                        printf("\tCouleur: %s\n", TabJt[i].TabJt[j].couleur);
                        printf("\tQuantite: %d\n", TabJt[i].TabJt[j].quantite);
                    }
                    printf("Prix: %.2f DT\n", TabJt[i].prix);
                    k++;
                    printf("------------------\n\n");
                }
            }if(k==1)
                printf("Pas de jouets pour les filles pour le moment!\n");
            break;

        case 3:
            for(i=0; i<nbJ; i++){
                if(TabJt[i].categorie.sexe == 'G'){
                    printf("------------------\n");
                    qtot = 0;
                    CalculerQuantiteTotale(TabJt, nbJ, TabJt[i].code, &qtot);
                    printf("Jouet n%d: \n", i+1);
                    printf("Quantite Total: %d\n", qtot);
                    printf("Code: %d\n", TabJt[i].code);
                    printf("Age: %d\n", TabJt[i].categorie.age);
                    printf("Sexe: %c\n", TabJt[i].categorie.sexe);
                    printf("Nombre de groupe de jouet: %d\n", TabJt[i].nbJ);
                    for(j=0; j<TabJt[i].nbJ; j++){
                        printf("// Groupe n%d:\n", j+1);
                        printf("\tCouleur: %s\n", TabJt[i].TabJt[j].couleur);
                        printf("\tQuantite: %d\n", TabJt[i].TabJt[j].quantite);
                    }
                    printf("Prix: %.2f DT\n", TabJt[i].prix);
                    k++;
                    printf("------------------\n\n");
                }
            }if(k==1)
                printf("Pas de jouets pour les Garcons pour le moment!\n");
            break;

        case 4:
            for(i=0; i<nbJ; i++){
                if(TabJt[i].prix<100){
                    printf("------------------\n");
                    qtot = 0;
                    CalculerQuantiteTotale(TabJt, nbJ, TabJt[i].code, &qtot);
                    printf("Jouet n%d: \n", i+1);
                    printf("Quantite Total: %d\n", qtot);
                    printf("Code: %d\n", TabJt[i].code);
                    printf("Age: %d\n", TabJt[i].categorie.age);
                    printf("Sexe: %c\n", TabJt[i].categorie.sexe);
                    printf("Nombre de groupe de jouet: %d\n", TabJt[i].nbJ);
                    for(j=0; j<TabJt[i].nbJ; j++){
                        printf("// Groupe n%d:\n", j+1);
                        printf("\tCouleur: %s\n", TabJt[i].TabJt[j].couleur);
                        printf("\tQuantite: %d\n", TabJt[i].TabJt[j].quantite);
                    }
                    printf("Prix: %.2f DT\n", TabJt[i].prix);
                    k++;
                    printf("------------------\n\n");
                }
            }if(k==1)
                printf("Pas de jouets inferieur de 100 DT pour le moment!\n");
            break;

        default: printf("Verifier votre choix!\n"); break;
    }
}

int donner_code()
{
    int code;

    printf("Taper le code: "); scanf("%d", &code);

    return code;
}

categorie JouetEnfant(jouet TabJt[], int nbJ, int codeJt)
{
    int x;
    categorie a;

    x = VerifierJouet(TabJt, nbJ, codeJt);
    if(x!=-1){
        a = TabJt[x].categorie;
        printf("Age: %d\n", a.age);
        printf("Sexe: %c\n", a.sexe);
    }else{
        a.age = -1;
        printf("Age: %d\n", a.age);
    }

    return a;
}

void TrierJouets(jouet TabJt[], int nbJ)
{
    int i, j, min;
    float temp;

    for(i=0; i<nbJ-1; i++){
        min = i;
        for(j=i+1; j<nbJ; j++){
            if(TabJt[min].prix>TabJt[j].prix){
                min = j;
            }
        }
        temp = TabJt[i].prix;
        TabJt[i].prix = TabJt[min].prix;
        TabJt[min].prix = temp;
    }
    if(nbJ==0)
        printf("Pas de jouets pour le moment!\n");
    else if(nbJ==1)
        printf("Vous avez une seule jouet pour le moment!\n");
    else
        printf("Tri a fini avec succes!\n");
}

void Initialiser(jouet MatriceJt[][30])
{
    int i, j;

    for(i=0; i<4; i++){
        for(j=0; j<30; j++){
            MatriceJt[i][j].code = 0;
        }
    }
}

void MettreEnPlaceRayon(jouet Jt, jouet MatriceJt[][30])
{
    int k=0, fait=0;

    while((k<30)&&(fait==0)){
        if((Jt.categorie.age>=0)&&(Jt.categorie.age<=2)&&((Jt.categorie.sexe=='F')||(Jt.categorie.sexe=='G'))){
            MatriceJt[0][k] = Jt;
            fait = 1;
        }else if((Jt.categorie.age==3)&&(Jt.categorie.sexe=='F')){
            MatriceJt[1][k] = Jt;
            fait = 1;
        }else if((Jt.categorie.age==3)&&((Jt.categorie.sexe=='G')||(Jt.categorie.sexe=='U'))){
            MatriceJt[2][k] = Jt;
            fait = 1;
        }else if((Jt.categorie.age==6)&&(Jt.categorie.sexe=='F')){
            MatriceJt[3][k] = Jt;
            fait = 1;
        }else if((Jt.categorie.age==6)&&((Jt.categorie.sexe=='G')||(Jt.categorie.sexe=='U'))){
            MatriceJt[4][k] = Jt;
            fait = 1;
        }else
            k++;
    }if(k>30)
        printf("Rayon est saturee!\n");
}

void MettreEnPlaceMagasin(jouet TabJt[], int nbJ, jouet MatriceJt[][30])
{
    int i, j, k=0;

    if(nbJ==0)
        printf("Pas de jouets a mettre en place!\n");
    else{
        for(i=0; i<nbJ; i++){
            MettreEnPlaceRayon(TabJt[i], MatriceJt);
        }
    }
    for(i=0; i<5; i++){
        printf("\nRayon n%d: ", k+1);
        j = 0;
        while((MatriceJt[i][j].code!=0)&&(j<30)){
            printf("%d | ", MatriceJt[i][j].code);
            j++;
        }
        k++;
    }
    printf("\n");
}
