#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Afficher Train\n");
    printf("2: Ajouter Locomotive\n");
    printf("3: Ajouter Wagon a la queue du train\n");
    printf("4: Rechercher Wagon donne par son numero\n");
    printf("5: Supprimer les wagons dont l'etat est en panne\n");
    printf("6: Ajouter un wagon apres le numero du wagon donne en parametre\n");
    printf("7: Supprimer le train [Liberer la mémoire]\n");
    printf("0: Exit\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)||(choix>7));

    return choix;
}

wagon saisirWagon(wagon w)
{
    printf("Numero: "); scanf("%d", &w.num);
    w.type = 2;
    do{
        printf("Etat: ([0] Panne - [1] Ok) "); scanf("%d", &w.etat);
    }while((w.etat != 0) && (w.etat != 1));

    return(w);
}

wagon saisirLocomotive(wagon w)
{
    printf("Numero: "); scanf("%d", &w.num);
    w.type = 1;
    do{
        printf("Etat: ([0] Panne - [1] Ok) "); scanf("%d", &w.etat);
    }while((w.etat != 0) && (w.etat != 1));

    return(w);
}

liste ajouterLocomotive(liste l, wagon w)
{
    cellule *nouv;
    FILE *file;

    file = fopen("historique.txt", "a+");
    if(file == NULL)
        printf("Error!\n");
    else{
        nouv = (cellule*) malloc(sizeof(cellule));
        if(nouv == NULL)
            printf("EROR: Memory struggle! (ajouterLocomotive function)\n");
        else{
            nouv->w = w;
            nouv->suivant = l;
            l = nouv;
            printf("Locomotive ajoute avec succes!\n");
            fprintf(file, "Locomotive %d a ete ajoute au train!\n", w.num);
        }
    }
    fclose(file);

    return(l);
}

liste ajouterWagon(liste l, wagon w)
{
    cellule *nouv, *parc;
    FILE *file;

    file = fopen("historique.txt", "a+");
    if(file == NULL)
        printf("Error!\n");
    else{
        nouv = (cellule*) malloc(sizeof(cellule));
        nouv->w = w;
        nouv->suivant = NULL;
        if(l==NULL){
            l=nouv;
            printf("Wagon ajoute avec succes!\n");
            fprintf(file, "Wagon %d a ete ajoute au train\n", w.num);
        }else{
            parc = l;
            while(parc->suivant != NULL){
                parc = parc->suivant;
            }
            parc->suivant = nouv;
            printf("Wagon ajoute avec succes!\n");
            fprintf(file, "Wagon %d a ete ajoute au train\n", w.num);
        }
    }
    fclose(file);

    return(l);
}

int longeurTrain(liste l)
{
    cellule *parc;
    int n=0;

    parc = l;
    if(l!=NULL){
        n = 1;
        while(parc->suivant != NULL){
            n++;
            parc = parc->suivant;
        }
    }

    return n;
}

int rechercherWagon(liste l, int num)
{
    cellule *parc;
    int trv=0, k=1;

    parc = l;
    while((k<longeurTrain(l)+1)&&(trv==0)){
        if(parc->w.num==num){
            trv = 1;
        }else{
            parc = parc->suivant;
            k++;
        }
    }

    if(trv==0){
        k = -1;
    }

    return(k);
}

void afficherTrain(liste l)
{
    cellule *tmp=l;

    if(l==NULL)
        printf("Le train est vide\n");
    else{
        while (tmp!=NULL){
            printf("Numero: %d  Type: %d ([1] Locomotive - [2] Wagon)  Etat: %d ([0] Panne - [1] Ok)\n",tmp->w.num, tmp->w.type, tmp->w.etat);
            tmp=tmp->suivant;
        }
    }
}

/**         PARTIE 2         **/

liste supprimer_deb(liste l){
    cellule *tmp;

    if(l!=NULL){
        tmp = l;
        l=l->suivant;
        free(tmp);
    }

    return(l);
}

liste SupprimerWagonPanne(liste l)
{
    cellule *courant=l, *precedent=l, *sup;
    int trouve=0;
    FILE *file;

    file = fopen("historique.txt", "a+");
    if(file == NULL)
        printf("Error!\n");
    else{
        if(l==NULL)
            printf("Train est vide!\n");
        else{
            while(courant!=NULL){
                if(l->w.etat == 0){
                    l = supprimer_deb(l);
                    courant = l;
                }else{
                    courant = l->suivant;
                    while(courant!=NULL){
                        if(courant->w.etat == 0){
                            sup = courant;
                            courant = courant->suivant;
                            precedent->suivant = courant;
                            free(sup);
                        }
                        if(courant!=NULL){
                            precedent = courant;
                            courant = courant->suivant;
                        }
                    }
                }
            }
            fprintf(file, "Tous les wagons en panne ont ete supprime avec succes!\n");
            printf("Tous les wagons en panne sont supprimes avec succes!\n");
        }
    }
    fclose(file);

    return l;
}

liste ajouterWagonDonne(liste l, wagon w, int num)
{
    cellule *nouv, *parc, *prec;
    int trouve = 0;
    FILE *file;

    file = fopen("historique.txt", "a+");
    if(file == NULL)
        printf("Error!\n");
    else{
        nouv = (cellule*) malloc(sizeof(cellule));
        nouv->w = w;
        if(l==NULL){
            printf("Wagon du num %d pas trouve! [Train Vide]\n", num);
            fprintf(file, "Ajout du wagon apres le wagon n%d failed [Train Vide].\n", num);
        }else{
            parc = l;
            while((trouve==0)&&(parc->suivant!=NULL)){
                parc = parc->suivant;
                if(parc->w.num == num)
                    trouve = 1;
            }
            if(trouve == 1){
                nouv->suivant = parc->suivant;
                parc->suivant = nouv;
                printf("Wagon ajoute avec succes!\n");
                fprintf(file, "Wagon %d a ete ajoute avec succes apres wagon n%d\n", w.num, num);
            }else{
                printf("Wagon du num %d pas trouve!\n", num);
                fprintf(file, "Ajout du wagon apres le wagon n%d failed. [Numero du wagon introuvable]\n", num);
            }
        }
    }

    return(l);
}

liste liberer(liste l)
{
    cellule *parc=l, *lib;

    while(parc!=NULL){
        lib = parc;
        parc = parc->suivant;
        free(lib);
    }

    return l;
}
