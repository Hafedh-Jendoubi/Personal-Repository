#include "functions.h"

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Test\n");
    printf("2: Ajouter Patient\n");
    printf("3: Nombre de patients avec et sans Rendez-vous\n");
    printf("4: Supprimer patient\n");
    printf("5: Consulter salle d'attente\n");
    printf("0: Sauvegarder et Exit\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: "); scanf("%d", &choix);
    }while((choix<0)||(choix>5));

    return choix;
}

void Test(liste tete)
{
    struct cellule *parc=tete;

    if(tete == NULL)
        printf("Liste Vide\n");
    else{
        while(parc!=NULL){
            afficherPatient(parc->p);
            parc = parc->suivant;
        }
    }
}

void saisirPatient(Patient *p)
{
    printf("Nom: "); scanf("%s", p->nom);
    printf("Prenom: "); scanf("%s", p->prenom);
    do{
        printf("Rendez-vous: ([0] Non - [1] Oui) "); scanf("%d", &p->rdv);
    }while((p->rdv!=0)&&(p->rdv!=1));
}

void afficherPatient(Patient p)
{
    printf("Nom: %s\n", p.nom);
    printf("Prenom: %s\n", p.prenom);
    printf("Rendez-vous: %d\t([0] Non - [1] Oui)\n\n", p.rdv);
}

liste AjoutPatient(liste tete, Patient p)
{
    struct cellule *nouv, *parc;

    nouv = (struct cellule*) malloc(sizeof(struct cellule));
    nouv->p = p;
    nouv->suivant = NULL;
    if(tete == NULL){
        tete = nouv;
    }else{
        parc = tete;
        while(parc->suivant != NULL)
            parc = parc->suivant;

        parc->suivant = nouv;
    }

    return(tete);
}

void RendezVous(liste tete, int *rdv, int *sansRdv)
{
    struct cellule *parc;
    *rdv = 0; *sansRdv = 0;

    parc = tete;
    if(tete == NULL)
        printf("Pas de patients!\n");
    else{
        while(parc != NULL){
            if(parc->p.rdv == 1)
                *rdv = *rdv + 1;
            else
                *sansRdv = *sansRdv + 1;
            parc = parc->suivant;
        }
        printf("Nombre de Patients avec Rendez-vous: %d\n", *rdv);
        printf("Nombre de Patients sans Rendez-vous: %d\n", *sansRdv);
    }
}

liste SupprimePatient(liste tete)
{
    struct cellule *parc=tete, *preced=tete;
    int trv=0;

    if(tete == NULL)
        printf("Il y'a pas de patients!\n");
    else{
        if(parc->suivant == NULL){
            free(parc);
            tete = NULL;
        }else{
            while((parc!=NULL)&&(trv == 0)){
                if(parc->p.rdv == 1){
                    trv = 1;
                }else{
                    preced = parc;
                    parc = parc->suivant;
                }
            }
            if(trv == 1){
                if(tete == parc){
                    tete = parc->suivant;
                    free(parc);
                }else{
                    preced->suivant = parc->suivant;
                    free(parc);
                }
            }else{
                parc = tete;
                tete = parc->suivant;
            }
        }
    }

    return tete;
}

void ConsulterSalleAttente(liste tete)
{
    struct cellule *parc=tete;

    if(tete == NULL)
        printf("Liste d'attente vide\n");
    else{
        while(parc!=NULL){
            if(parc->p.rdv==1)
                afficherPatient(parc->p);
            parc = parc->suivant;
        }
        parc = tete;
        while(parc!=NULL){
            if(parc->p.rdv==0)
                afficherPatient(parc->p);
            parc = parc->suivant;
        }
    }

}

void sauvegarderPatients(liste tete, char chemin[])
{
    FILE *file;
    struct cellule *parc=tete;
    int i=1;

    file = fopen(chemin, "w+");
    if(file == NULL)
        printf("EROR: Memory Struggle!\n");
    else{
        while(parc!=NULL){
            fprintf(file, "Patient n%d:\n\tNom: %s\n\tPrenom: %s\n\tRendez-vous: %d ([0] Non - [1] Oui)\n\n", i, parc->p.nom, parc->p.prenom, parc->p.rdv);
            i++;
            parc = parc->suivant;
        }
    }
    fclose(file);

}

liste recupererListePatients(liste tete, char chemin[])
{
    struct cellule *nouv, *parc;
    Patient p;
    FILE *file;
    int i;

    file = fopen(chemin, "a+");
    if(file == NULL)
        printf("EROR: Memory Struggle!\n");
    else{
        while(!feof(file)){  /** <-------------- The problem is this loop: Can't know the condition of reading all the file!! **/
            fscanf(file, "Patient n%d:\n\tNom: %s\n\tPrenom: %s\n\tRendez-vous: %d ([0] Non - [1] Oui)\n\n", i, p.nom, p.prenom, p.rdv);
            nouv = (struct cellule*) malloc(sizeof(struct cellule));
            if(nouv == NULL)
                printf("EROR: Struggle Memory! [Creating nouv]\n");
            else{
                nouv->p = p;
                nouv->suivant = NULL;
                if(tete == NULL)
                    tete = nouv;
                else{
                    parc = tete;
                    while(parc->suivant!=NULL)
                        parc = parc->suivant;
                    parc->suivant = nouv;
                }
            }
        }
    }
    fclose(file);

    return tete;
}
