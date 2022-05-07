#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Saisir les informations d'une machine\n");
    printf("2- Ajouter une machine\n");
    printf("3- Chercher une machine donnee par sa reference\n");
    printf("4- Saisir les informations d'une panne\n");
    printf("5- Ajouter une panne a une machine\n");
    printf("6- Calculer le nombre total des pannes d'une machine\n");
    printf("7- Modifier l'etat d'une/plusieurs pannes d'une machine\n");
    printf("8- Afficher les pannes d'une machine\n");
    printf("9- Calculer le nombre total des pannes reparees et non reparees d'une machine\n");
    printf("10- Supprimer les machines dont le nombre des pannes reparees est egal au nombre de pannes total\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)&&(choix>10));

    return choix;
}

void saisir(machine *m)
{
    int i;

    printf("Reference: "); scanf("%d", &(*m).refmachine);
    for(i=0; i<10; i++)
        (*m).P[i].refpanne[0] = '\0';
}

void ajouter(machine Tm[], machine m, int *n)
{
        Tm[(*n)] = m;
        (*n)++;
        printf("Machine ajoutee avec sucess!\n");
}

int taperref(int ref)
{
    printf("Taper la reference de la machine: "); scanf("%d", &ref);
    return ref;
}

int rechercherMach(machine Tm[], int n, int ref)
{
    int trv, k;

    trv = -1; k = 0;
    while((trv==-1)&&(k<n)){
        if(Tm[k].refmachine == ref)
            trv = k;
        else
            k++;
    }

    return trv;
}

void saisirPanne(panne *p)
{
    printf("Reference du panne: "); fflush(stdin); gets((*p).refpanne);
    printf("Etat: ([1] Reparee - [0] Non Reparee) "); scanf("%d", &(*p).etat);
}

void ajouterPanne(int ref, machine Tm[], int n, panne p)
{
    int i, k=0, trv=0;

    for(i=0; i<n; i++){
        if(Tm[i].refmachine == ref){
            while((trv==0)&&(k<10)){
                if(Tm[i].P[k].refpanne[0] == '\0'){
                    trv = 1;
                    Tm[i].P[k] = p;
                    printf("Panne ajoutee avec sucess!\n");
                }else
                    k++;
            }
        }
    }
    if(k>10)
        printf("Cette machine admet 10 pannes!\n");
    if(trv==0)
        printf("Verifier votre reference!\n");
}

int totalPanne(int ref, machine Tm[], int n)
{
    int i=0, comp=0, k=0, trv=0;

    while((trv==0)&(k<n)){
        if(Tm[k].refmachine == ref){
            trv = 1;
            while(i<10){
                if(Tm[k].P[i].refpanne[0] != '\0'){
                    i++;
                    comp++;
                }else{
                    break;
                }
            }
        }else{
            k++;
        }
    }
    if(trv==0){
        printf("Verifier votre reference!\n");
        comp = -1;
    }

    return comp;
}

void modifier_etat_panne(int ref, machine Tm[], int n)
{
    int k=0, trv=0, ch, pid;

    while((trv==0)&&(k<n)){
        if(Tm[k].refmachine == ref){
            trv = 1; printf("0- Exit\n1- Modifier l'etat d'une panne\n");
            do{
                printf("Taper votre choix: "); scanf("%d", &ch);
                switch(ch){
                    case 0:
                        printf("...\n"); break;
                    case 1:
                        printf("Taper l'id du panne a modifier: "); scanf("%d", &pid);
                        Tm[k].P[pid].etat = 1;
                        printf("Panne etat modifie!\n"); break;
                }
            }while(ch!=0);
        }else{
            k++;
        }
    }
    if(trv==0)
        printf("Verifier votre reference!\n");
}

void afficher(int n, machine Tm[], int ref)
{
    int trv=0, k=0, i;

    while((trv==0)&&(k<n)){
        if(Tm[k].refmachine == ref){
            trv = 1;
            if(totalPanne(ref, Tm, n)==0)
                printf("Cette machine n'ademt pas de pannes!\n");
            else{
                for(i=0; i<totalPanne(ref, Tm, n); i++){
                    printf("----------------------\nPanne n%d:\n", i);
                    printf("Reference: "); puts(Tm[k].P[i].refpanne);
                    printf("Etat: %d\n----------------------\n", Tm[k].P[i].etat);
                }
            }
        }else{
            k++;
        }
    }
    if(trv==0)
        printf("Verifier votre reference!\n");
}

void trouver(machine Tm[], int n, int *n_rep, int *n_nrep, int ref)
{
    int trv=0, k=0, i;

    while((trv==0)&&(k<n)){
        if(Tm[k].refmachine == ref){
            trv = 1;
            for(i=0; i<totalPanne(ref, Tm, n); i++){
                if(Tm[k].P[i].etat == 0)
                    (*n_nrep)++;
                else
                    (*n_rep++);
            }
            printf("Machine %d:\n", ref);
            printf("Le nombre total des pannes reparees: %d\n", (*n_rep));
            printf("Le nombre total des pannes non reparees: %d\n", (*n_nrep));
        }else{
            k++;
        }
    }
    if(trv==0)
        printf("Verifier votre reference!\n");
}

void supprimer(machine Tm[], int *n)
{
    /** Will finish it **/
}
