#include "functions.h"

void afficher_clients(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l;
        int k = 0;
        while(parc!=NULL){
            k++; printf("Client n%d:\n", k);
            printf("Nom: %s\nAge: %d\nCash: %.2f\n\n", parc->c.nom, parc->c.age, parc->c.cash);
            parc = parc->suivant;
        }
    }
}

client saisir_client()
{
    client c;

    printf("Nom: "); scanf("%s", c.nom);
    printf("Age: "); scanf("%d", &c.age);
    printf("Cash: "); scanf("%f", &c.cash);

    return c;
}

liste ajouter_client_premier(liste l)
{
    liste nouv;
    client c;

    nouv = (struct cellule*) malloc(sizeof(struct cellule));
    if(nouv == NULL)
        printf("Eror: Struggle Memory! (ajouter_client_premier)\n");
    else{
        c = saisir_client();
        nouv->c = c;
        nouv->suivant = l;
        l = nouv;
        printf("Client ajoute avec succes!\n");
    }

    return l;
}

liste ajouter_client_apres(liste l)
{
    liste nouv;
    client c;

    nouv = (struct cellule*) malloc(sizeof(struct cellule));
    if(nouv == NULL)
        printf("Eror: Struggle Memory! (ajouter_client_apres)\n");
    else{
        if(l==NULL)
            printf("Pas de clients a ajouter apres!\n");
        else{
            liste parc=l; char nom[10];
            printf("Taper le nom du client que vous voulez ajouter apres lui cette client: "); scanf("%s", nom);
            while(parc!=NULL){
                if(strcmp(parc->c.nom, nom)==0){
                    nouv->suivant = parc->suivant;
                    parc->suivant = nouv;
                    break;
                }
                parc = parc->suivant;
            }
            if(parc==NULL)
                printf("Client %s pas trouve! Verifier le nom svp.\n", nom);
            else{
                c = saisir_client();
                nouv->c = c;
                printf("Client ajoute avec succes!\n");
            }
        }
    }

    return l;
}

liste ajouter_client_fin(liste l)
{
    liste nouv;
    client c;

    nouv = (struct cellule*) malloc(sizeof(struct cellule));
    if(nouv == NULL)
        printf("Eror: Struggle Memory! (ajouter_client_fin)\n");
    else{
        c = saisir_client();
        nouv->c = c;
        nouv->suivant = NULL;
        if(l==NULL)
            l = nouv;
        else{
            liste parc=l;
            while(parc->suivant!=NULL)
                parc = parc->suivant;
            parc->suivant = nouv;
        }
        printf("Client ajoute avec succes!\n");
    }

    return l;
}

liste supprimer_client_premier(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste suppr;
        suppr = l;
        l = l->suivant;
        free(suppr);
        printf("Client supprime avec succes!\n");
    }

    return l;
}

liste supprimer_client_nom(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        char nom[10]; liste parc=l, preced;
        printf("Taper le nom du client a supprimer: "); scanf("%s", nom);
        while(parc!=NULL){
            if(strcmp(parc->c.nom, nom)==0){
                if(parc==l)
                    l = l->suivant;
                else
                    preced->suivant = parc->suivant;
                free(parc);
                break;
            }
            preced = parc;
            parc = parc->suivant;
        }
        if(parc==NULL)
            printf("Client %s pas trouve! Verifier le nom svp.\n", nom);
        else
            printf("Client supprime avec succes!\n");
    }

    return l;
}

liste supprimer_client_fin(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        if(l->suivant == NULL){
            free(l);
            l = NULL;
        }else{
            liste parc=l, preced;
            while(parc->suivant!=NULL){
                preced = parc;
                parc = parc->suivant;
            }
            preced->suivant = NULL;
            free(parc);
        }
        printf("Client supprime avec succes!\n");
    }

    return l;
}

liste supprimer_tous(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l, preced;
        while(parc!=NULL){
            preced = parc;
            parc = parc->suivant;
            free(preced);
        }
        l = NULL;
        printf("Tous les clients ont ete supprime avec succes!\n");
    }

    return l;
}

void search_client_name(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; char nom[10]; int k=0;
        printf("Taper le nom: "); scanf("%s", nom);
        while(parc!=NULL){
            if(strcmp(parc->c.nom, nom)==0){
                k++; printf("Details sur %s numero %d:\n", nom, k);
                printf("Nom: %s\nAge: %d\nCash: %.2f\n\n", parc->c.nom, parc->c.age, parc->c.cash);
            }
            parc = parc->suivant;
        }
        if(k==0)
            printf("**Information**\n\t%s n'existe pas dans la liste des clients!\n", nom);
        else
            printf("**Information**\n\tIl existe %d clients nomme %s\n", k, nom);
    }
}

void search_client_age(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; int a, k=0;
        printf("Taper l'age: "); scanf("%d", &a);
        while(parc!=NULL){
            if(parc->c.age == a){
                k++; printf("Details sur l'agee %d numero %d:\n", a, k);
                printf("Nom: %s\nAge: %d\nCash: %.2f\n\n", parc->c.nom, parc->c.age, parc->c.cash);
            }
            parc = parc->suivant;
        }
        if(k==0)
            printf("**Information**\n\tIl ya pas a client d'age %d dans la liste des clients!\n", a);
        else
            printf("**Information**\n\tIl existe %d clients agee %d\n", k, a);
    }
}

void search_client_cash(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; float min, max; int k=0;
        do{
            printf("Taper le prix min: "); scanf("%f", &min);
        }while(min<0);
        do{
            printf("Taper le prix max: "); scanf("%f", &max);
        }while(max<min);
        while(parc!=NULL){
            if((parc->c.cash>=min)&&(parc->c.cash<=max)){
                k++; printf("Details sur client ayant cash dans l'interval [%.2f - %.2f] numero %d:\n", min, max, k);
                printf("Nom: %s\nAge: %d\nCash: %.2f\n\n", parc->c.nom, parc->c.age, parc->c.cash);
            }
            parc = parc->suivant;
        }
        if(k==0)
            printf("**Information**\n\tIl ya pas client ayant cash dans l'interval [%.2f - %.2f]\n", min, max);
        else
            printf("**Information**\n\tIl existe %d clients ayant cash dans l'interval [%.2f - %.2f]\n", k, min, max);
    }
}

void search_oldest_client(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; int age=parc->c.age;
        while(parc!=NULL){
            if(parc->c.age > age)
                age = parc->c.age;
            parc = parc->suivant;
        }
        parc = l; printf("The oldest client(s):\n");
        while(parc!=NULL){
            if(parc->c.age == age)
                printf("Client: Nom: %s  Age: %d\n", parc->c.nom, age);
            parc = parc->suivant;
        }
    }
}

void search_youngest_client(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; int age=parc->c.age;
        while(parc!=NULL){
            if(parc->c.age < age)
                age = parc->c.age;
            parc = parc->suivant;
        }
        parc = l; printf("The youngest client(s):\n");
        while(parc!=NULL){
            if(parc->c.age == age)
                printf("Client: Nom: %s  Age: %d\n", parc->c.nom, age);
            parc = parc->suivant;
        }
    }
}

void search_richest_client(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; float c=parc->c.cash;
        while(parc!=NULL){
            if(parc->c.cash > c)
                c = parc->c.cash;
            parc = parc->suivant;
        }
        parc = l; printf("The richest client(s):\n");
        while(parc!=NULL){
            if(parc->c.cash == c)
                printf("Client: Nom: %s  Cash: %.2f\n", parc->c.nom, c);
            parc = parc->suivant;
        }
    }
}

void search_poorest_client(liste l)
{
    if(l==NULL)
        printf("Pas de clients!\n");
    else{
        liste parc=l; float c=parc->c.cash;
        while(parc!=NULL){
            if(parc->c.cash < c)
                c = parc->c.cash;
            parc = parc->suivant;
        }
        parc = l; printf("The poorest client(s):\n");
        while(parc!=NULL){
            if(parc->c.cash == c)
                printf("Client: Nom: %s  Cash: %.2f\n", parc->c.nom, c);
            parc = parc->suivant;
        }
    }
}
