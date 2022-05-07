#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Ajouter un livre\n");
    printf("2: Afficher tous les livres\n");
    printf("3: Ajouter un emprunt\n");
    printf("4: Retourner un emprunt\n");
    printf("5: Afficher tous les emprunts retournes\n");
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

void saisir_livre(Livre *p_livre)
{
    printf("Code du Livre: "); scanf("%d", &p_livre->code);
    printf("Nombre d'exemplaires: "); scanf("%d", &p_livre->nb_exemp);
}

void chercher_livre(Livre t_livres[], int nl, int code_l, int* pos)
{
    int trouve=0, k=0;

    while((k<nl)&&(trouve==0)){
        if(t_livres[k].code==code_l){
            trouve = 1;
            (*pos) = k;
        }else
            k++;
    }
    if(trouve==0)
        (*pos) = -1;
}

void ajouter_livre(Livre t_livres[], int *nl)
{
    Livre p_livre;
    int pos;

    saisir_livre(&p_livre);
    chercher_livre(t_livres, *nl, p_livre.code, &pos);
    if(pos!=-1){
        t_livres[pos].nb_exemp = t_livres[pos].nb_exemp + p_livre.nb_exemp;
        printf("Livre existe deja. Nombre d'exemplaires a ete incremente!\n");
    }else{
        t_livres[(*nl)] = p_livre;
        (*nl)++;
        printf("Livre ajoute avec sucecs!\n");
    }
}

void afficher_livres(Livre t_livres[], int nl)
{
    int i;
    if(nl==0)
        printf("Pas de livres pour le moment!\n");
    else{
        for(i=0; i<nl; i++){
            printf("---- Livre n%d ----\n", i+1);
            printf("Code: %d\n", t_livres[i].code);
            printf("Nombre d'exemplaires: %d\n\n", t_livres[i].nb_exemp);
        }
    }
}

void saisir_emprunt(Emprunt *p_emprunt)
{
    printf("Numero d'emprunt: "); scanf("%d", &p_emprunt->numero);
    printf("Code du livre emprunte: "); scanf("%d", &p_emprunt->code_livre);
    printf("L'identifiant de l'abonne: "); fflush(stdin); gets(p_emprunt->id_abonne);
    p_emprunt->etat = 0;
}

void chercher_emprunt(int num, Emprunt t_emprunts[], int ne, int *pos)
{
    int trouve=0, k=0;

    while((k<ne)&&(trouve==0)){
        if(t_emprunts[k].numero==num){
            trouve = 1;
            (*pos) = k;
        }else
            k++;
    }
    if(trouve==0)
        (*pos) = -1;
}

void ajouter_emprunt(Emprunt t_emprunts[], int* ne, Livre t_livres[], int nl)
{
    Emprunt p_emprunt;
    int pos_e, pos_l;

    saisir_emprunt(&p_emprunt);
    chercher_emprunt(p_emprunt.numero, t_emprunts, (*ne), &pos_e);
    if(pos_e!=-1){
        printf("Erreur! [Emprunt existe deja!]\n");
    }else{
        chercher_livre(t_livres, nl, p_emprunt.code_livre, &pos_l);
        if((pos_l!=-1)&&(t_livres[pos_l].nb_exemp>=1)){
            t_livres[pos_l].nb_exemp--;
            t_emprunts[(*ne)] = p_emprunt;
            (*ne)++;
            printf("Emprunt ajoutee avec succes!\n");
        }else
            printf("Erreur! [Livre n'existe pas ou le nombre d'exemplaires de ce livre est null]\n");
    }
}

void retourner_emprunt(int num, Emprunt t_emprunts[], int ne, Livre t_livres[], int nl)
{
    int pos_l, pos_e;

    chercher_emprunt(num, t_emprunts, ne, &pos_e);
    if((pos_e!=-1)&&(t_emprunts[pos_e].etat==0)){
        chercher_livre(t_livres, nl, t_emprunts[pos_e].code_livre, &pos_l);
        if(pos_l!=-1)
            t_livres[pos_l].nb_exemp++;
        else
            printf("Erreur! [Livre n'existe pas]\n");
        t_emprunts[pos_e].etat = 1;
        printf("Emprunt etat a ete mis a jour!\n");
    }else
        printf("Erreur! [Emprunt n'existe pas ou deja retourne]\n");
}

void afficher_emprunts_retournes(Emprunt t_emprunts[], int ne)
{
    int i, k=0;

    for(i=0; i<ne; i++){
        if(t_emprunts[i].etat==1){
            k++;
            printf("Emprunt retourne n%d:\n", k);
            printf("\tNumero: %d\n", t_emprunts[i].numero);
            printf("\tCode du Livre: %d\n", t_emprunts[i].code_livre);
            printf("\tL'identifiant de l'abonne: %s\n", t_emprunts[i].id_abonne);
            printf("\tEtat: %d\n\n", t_emprunts[i].etat);
        }
    }
    if(k==0)
        printf("Pas d'emprunts retourne pour le moment!\n");
}
