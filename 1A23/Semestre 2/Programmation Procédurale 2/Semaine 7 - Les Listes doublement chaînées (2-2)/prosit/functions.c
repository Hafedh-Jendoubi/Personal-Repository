#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Ajouter une station\n");
        printf("2- Supprimer une station\n");
        printf("3- Afficher le chemin de la competition\n");
        printf("4- Inistialiser la competition\n");
        printf("5- Suivre l'avancement d'un alpiniste\n");
        printf("6- Afficher l'avancement des alpinistes\n");
        printf("7- Afficher le gagnant de la competition\n");
        printf("0- Quitter\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>7));
}

/** Partie I **/

void initchemin(LDC *l)
{
    l->tete = NULL;
    l->queu = NULL;
}

station saisir_station()
{
    station s;
    int i;

    do{
        printf("Numero de la station: "); scanf("%d", &s.num);
    }while(s.num<1);
    printf("La distance qui la separe de la station precedente: "); scanf("%f", &s.dist);
    for(i=0; i<=2; i++){
        strcpy(s.A[i].id, "-1");
        s.A[i].h1.h = -1;
        s.A[i].h1.m = -1;
        s.A[i].h1.s = -1;
        s.A[i].h2.h = -1;
        s.A[i].h2.m = -1;
        s.A[i].h2.s = -1;
    }

    return s;
}

int liste_vide(LDC l)
{
    if(l.tete == NULL && l.queu == NULL)
        return 1;
    else
        return 0;
}

cellule* chercher_station(LDC l, int num)
{
    cellule *parc=l.tete;

    if(liste_vide(l)==1) /** Case: Empty List **/
        parc = NULL;
    else{
        while(parc!=NULL){
            if(parc->s.num == num)
                break;
            parc = parc->suiv;
        }
    }

    return parc;
}

LDC ajouter_debut(LDC l, station s)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->s = s;
    nouv->suiv = l.tete;
    nouv->prec = NULL;
    if(liste_vide(l)==1)
        l.queu = nouv;
    else
        l.tete->prec = nouv;
    l.tete = nouv;

    return l;
}

LDC ajouter_fin(LDC l, station s)
{
    cellule *nouv;

    nouv = (cellule*) malloc(sizeof(cellule));
    nouv->s = s;
    nouv->suiv = NULL;
    nouv->prec = l.queu;
    if(liste_vide(l)==1)
        l.tete = nouv;
    else
        l.queu->suiv = nouv;
    l.queu = nouv;

    return l;
}

LDC ajouter_station(LDC l)
{
    station s;
    cellule *trv, *nouv;

    s = saisir_station();
    trv = chercher_station(l, s.num);
    if(trv != NULL)
        printf("Station existe deja!\n");
    else{
        nouv = (cellule*) malloc(sizeof(cellule));
        nouv->s = s;
        if(liste_vide(l)==1){
            l = ajouter_debut(l, s);
        }else{
            if(l.tete->s.num > nouv->s.num)
                l = ajouter_debut(l, s);
            else if(l.queu->s.num < nouv->s.num)
                l = ajouter_fin(l, s);
            else{
                trv = l.tete;
                while(trv->s.num < nouv->s.num)
                    trv = trv->suiv;
                nouv->suiv = trv;
                nouv->prec = trv->prec;
                trv->prec = nouv;
                nouv->prec->suiv = nouv;
            }
        }
        printf("Station ajoute avec succes!\n");
    }

    return l;
}

void Afficher_Chemin(LDC l)
{ 
    cellule *p;

    if(liste_vide(l) == 1)
        printf("Pas de stations!\n");
    else{
        p = l.queu;
        printf("*** Chemin: ***\n");
        while(p){
            printf("Station %d\n", p->s.num);
            if(p->prec != NULL)
                printf("   |^\n   ||\n");
            p = p->prec;
        }
    }
}

void initialiser_alpiniste(LDC l, alpiniste *a)
{
    int trv, i;
    char id[10];

    do{
        trv = 0;
        printf("L'ID de l'alpiniste: "); scanf("%s", id);
        for(i=0; i<=2; i++){
            if(strcmp(l.tete->s.A[i].id, id)==0){
                trv = 1;
                break;
            }
        }
    }while(trv == 1);
    strcpy(a->id, id);

    a->h1.h = 8;
    a->h1.m = 0;
    a->h1.s = 0;
    printf("Termine avec succes!\n\n");
}

LDC init_competition(LDC l)
{
    if(liste_vide(l) == 1)
        printf("Pas de stations!\n");
    else{
        int i;

        for(i=0; i<=2; i++){
            printf("Alpiniste n%d:\n", i+1);
            initialiser_alpiniste(l, l.tete->s.A+i);
        }
    }

    return l;
}

/** Partie II **/

LDC supprimer_debut(LDC l)
{
    cellule *suppr;

    suppr = l.tete;
    l.tete = l.tete->suiv;
    if(l.tete == NULL)
        l.queu = NULL;
    else
        l.tete->prec = NULL;
    free(suppr);

    return l;
}

LDC supprimer_fin(LDC l)
{
    cellule *suppr;

    suppr = l.queu;
    l.queu = l.queu->prec;
    if(l.queu == NULL)
        l.tete = NULL;
    else
        l.queu->suiv = NULL;
    free(suppr);

    return l;
}

LDC supprimer_station(LDC l)
{
    int x;
    cellule *parc;

    if(liste_vide(l) == 1)
        printf("Pas de stations!\n");
    else{
        printf("Numero du station a supprimer: "); scanf("%d", &x);
        parc = chercher_station(l, x);
        if(parc == NULL) //Cas Station n°x n'existe pas
            printf("Station %d n'existe pas!\n", x);
        else{ //Autre cas
            if(l.tete->s.num == x) //Cas du premier element
                l = supprimer_debut(l);
            else if(l.queu->s.num == x) //Cas du dernier element
                l = supprimer_fin(l);
            else{ //Autre cas
                parc->prec->suiv = parc->suiv;
                parc->suiv->prec = parc->prec;
                free(parc);
            }
            printf("Station %d a ete supprime avec succes!\n", x);
        }
    }

    return l;
}

void suivre_montee_alpiniste(cellule *parc, char id[])
{
    int trv=0, i;
    
    for(i=0; i<=2; i++){
        if(strcmp(parc->s.A[i].id, "-1")==0)
            break;
        if(strcmp(parc->s.A[i].id, id)==0){
            trv = 1;
            break;
        }
    }
    if(trv == 1)
        printf("Alpiniste %s est deja passe par cette station!\n", id);
    else{
        strcpy(parc->s.A[i].id, id);
        printf("\n1ere passage: (Montant)\n");
        do{
            printf("Heure: "); scanf("%d", &parc->s.A[i].h1.h);
        }while(parc->s.A[i].h1.h<8);
        do{
            printf("Minute(s): "); scanf("%d", &parc->s.A[i].h1.m);
        }while((parc->s.A[i].h1.m<0)||(parc->s.A[i].h1.m>59));
        do{
            printf("Seconde(s): "); scanf("%d", &parc->s.A[i].h1.s);
        }while((parc->s.A[i].h1.s<0)||(parc->s.A[i].h1.s>59));
    }
}

void suivre_descente_alpiniste(cellule *parc, char id[])
{
    int i;

    for(i=0; i<=2; i++){
        if(strcmp(parc->s.A[i].id, id) == 0)
            break;
    }
    printf("\n2eme passage: (Descendant)\n");
    if(parc->suiv == NULL){
        parc->s.A[i].h2.h = parc->s.A[i].h1.h;
        parc->s.A[i].h2.m = parc->s.A[i].h1.m;
        parc->s.A[i].h2.s = parc->s.A[i].h1.s;
        printf("Le temps de montee est le meme de descendant dans la station %d car elle est la dernier.\n", parc->s.num);
    }else{
        do{
            printf("Heure: "); scanf("%d", &parc->s.A[i].h2.h);
        }while(parc->s.A[i].h2.h<8);
        do{
            printf("Minute(s): "); scanf("%d", &parc->s.A[i].h2.m);
        }while((parc->s.A[i].h2.m<0)||(parc->s.A[i].h2.m>59));
        do{
            printf("Seconde(s): "); scanf("%d", &parc->s.A[i].h2.s);
        }while((parc->s.A[i].h2.s<0)||(parc->s.A[i].h2.s>59));
    }

}

void suivre_alpiniste(LDC l)
{
    int x, i;
    cellule *parc;
    char id[10];

    if(liste_vide(l) == 1)
        printf("Pas de stations!\n");
    else{
        printf("ID de l'alpiniste a suivre: "); scanf("%s", id);
        for(i=0; i<=2; i++){
            if(strcmp(id, l.tete->s.A[i].id)==0)
                break;
        }
        if(i==3)
            printf("Verifier l'ID: %s\n", id);
        else{
            printf("Numero de station: "); scanf("%d", &x);
            parc = chercher_station(l, x);
            if(parc == NULL)
                printf("Station %d n'existe pas!\n", x);
            else{
                suivre_montee_alpiniste(parc, id);
                suivre_descente_alpiniste(parc, id);
                printf("**\nStation %d Information**\n\tMise a jour de l'Alpiniste %s a ete fait avec succes.\n", x, id);
            }
        }
    }

}

void afficher_avancement(LDC l)
{
    int x, i, n;
    cellule *parc;
    char id[10];

    if(liste_vide(l)==1)
        printf("Pas de station!\n");
    else{
        printf("Numero de station: "); scanf("%d", &x);
        parc = chercher_station(l, x);
        if(parc == NULL)
            printf("Station %d n'existe pas!\n", x);
        else{
            printf("ID de l'Alpiniste: "); scanf("%s", id);
            for(i=0; i<=2; i++){
                if(strcmp(parc->s.A[i].id, id)==0)
                    break;
            }
            if(i==3)
                printf("Verifier l'ID %s.\n", id);
            else{
                n = 3600*(parc->s.A[i].h2.h-parc->s.A[i].h1.h) + 60*(parc->s.A[i].h2.m-parc->s.A[i].h1.m) + (parc->s.A[i].h2.s-parc->s.A[i].h1.s);
                printf("**Station %d Information**\n", x);
                printf("\tAvancement de l'Alpiniste %s: %d Heure(s) - %d Minute(s) - %d Seconde(s)\n", id, n/3600, (n/60)%60, n%60);
            }
        }
    }

}

int calculer_duree_escalade(LDC l, char id[], int *des, int *mont)
{
    int i, f;

    for(i=0; i<=2; i++){
        if(strcmp(l.tete->s.A[i].id, id)==0)
            break;
    }
    if(i==3)
        printf("Alpinisde d'ID %s n'existe pas!\n", id);
    else{
        for(f=0; f<=2; f++){
            if(strcmp(l.queu->s.A[f].id, id)==0)
                break;
        }
        *mont = 3600*(l.queu->s.A[f].h1.h-8) + 60*(l.queu->s.A[f].h1.m-l.tete->s.A[f].h1.m) + (l.queu->s.A[f].h1.s-l.tete->s.A[i].h1.s);
        *des = 3600*(l.tete->s.A[i].h2.h-l.queu->s.A[f].h2.h) + 60*(l.tete->s.A[i].h2.m-l.queu->s.A[f].h2.m) + (l.tete->s.A[i].h2.s-l.queu->s.A[f].h2.s);
    }

    return (*des + *mont);
}

void gagnant_Escalade(LDC l)
{
    char id[10], id_winn[10];
    int i, des, mont, res, n, montw, desw;

    for(i=0; i<=2; i++){
        strcpy(id, l.tete->s.A[i].id);
        res = calculer_duree_escalade(l, id, &des, &mont);
        if(i==0){
            n = res; montw = mont; desw = des;
            strcpy(id_winn, id);
        }else{
            if(res < n){
                n = res; montw = mont; desw = des;
                strcpy(id_winn, id);
            }
        }
    }

    printf("**Winner Information**\n");
    printf("\tWinner ID: %s\n\tDuree Total d'Escalade: %d Heure(s) - %d Minute(s) - %d Seconde(s)\n", id_winn, n/3600, (n/60)%60, n%60);
    printf("\tDuree Total d'Escalade en montee: %d Heure(s) - %d Minute(s) - %d Seconde(s)\n", montw/3600, (montw/60)%60, montw%60);
    printf("\tDuree Total d'Escalade en descente: %d Heure(s) - %d Minute(s) - %d Seconde(s)\n", desw/3600, (desw/60)%60, desw%60);
}