#include "functions.h"

/** Partie 1: **/

void menuprincipal()
{
    printf("~~~~~~~~~ Menu: ~~~~~~~~~~~\n");
    printf("1: Ajouter dossier\n");
    printf("2: Retirer dossier\n");
    printf("3: Consulter le dernier dossier\n");
    printf("4: Placer les dossiers de priorite 1 au dessus des dossiers de priorite 2\n");
    printf("5: Deplacer les dossiers du pile vers la file\n");
    printf("6: Consulter le premier dossier de la file\n");
    printf("7: Retirer un dossier de la file afin de le traiter\n");
    printf("0: Exit\n");
}

int menu()
{
    int choix;

    do{
        printf("\nTaper votre choix: ");
        scanf("%d", &choix);
    }while((choix<0)||(choix>7));

    return choix;
}

dossier saisir_dossier()
{
    dossier d;

    printf("Numero: ");
    scanf("%d", &d.num);
    do{
        printf("Priorite: (1: priorite elevee, 2: priorite faible) ");
        scanf("%d", &d.priority);
    }while((d.priority<1)||(d.priority>2));

    return d;
}

pile ajouter_dossier(pile p)
{
    pile nouv;
    dossier d;

    d = saisir_dossier();
    nouv = malloc(sizeof(struct cellule));
    nouv->d = d;
    nouv->suivant = p;
    p = nouv;

    return p;
}

pile retirer_dossier(pile p)
{
    pile suppr;

    if(p==NULL)
        printf("Pas de dossier a retirer!\n");
    else{
        suppr = p;
        p = p->suivant;
        free(suppr);
        printf("Dossier a ete retire avec succes!\n");
    }

    return p;
}

void dernier_dossier(pile p)
{
    pile parc;

    if(p==NULL)
        printf("Pas de dossier!\n");
    else{
        parc = p;
        while(parc->suivant != NULL)
            parc = parc->suivant;
        printf("Le dernier dossier est Dossier:\n");
        printf("Numero: %d\nPriorite: %d\n\n", parc->d.num, parc->d.priority);
    }
}

pile free_pile(pile p)
{
    pile parc, suppr;

    parc = p;
        while(parc!=NULL){
            suppr = parc;
            parc = parc->suivant;
            free(suppr);
        }
    p = NULL;

    return p;
}

pile mettrePile_dansPile(pile p, pile ap)
{
    pile parc, nouv;

    parc = ap;
    while(parc!=NULL){
        nouv = malloc(sizeof(struct cellule));
        nouv->d = parc->d;
        nouv->suivant = p;
        p = nouv;
        parc = parc->suivant;
    }
    ap = free_pile(ap);

    return p;
}

pile permutation(pile p)
{
    pile p1=NULL, p2=NULL, parc, nouv, suppr;

    if(p==NULL)
        printf("Pas de dossier!\n");
    else{ /** Deplacement de p dans p1 (p1 = dossiers de priorite 1) et p2 (p2 = dossiers de priorite 2) **/
        parc = p;
        while(parc!=NULL){
            nouv = malloc(sizeof(struct cellule));
            nouv->d = parc->d;
            if(parc->d.priority==1){
                nouv->suivant = p1;
                p1 = nouv;
            }else{
                nouv->suivant = p2;
                p2 = nouv;
            }
            parc = parc->suivant;
        }

        /** Depilage du pile p **/
        p = free_pile(p);

        /** Piler p2 dans p puis, p1 pour avoir les dossiers de propriete 1 au dessus **/
        /** Pilage de p2 dans p: **/
        p = mettrePile_dansPile(p, p2);
        /** Pilage de p1 dans p: **/
        p = mettrePile_dansPile(p, p1);

        printf("Arrangement fait avec succes!\n");
    }

    return p;
}

/** Partie 2: **/

file initFile()
{
    file f;
    f.tete = NULL;
    f.queu = NULL;

    return f;
}

file deplacer(file f, pile *p)
{
    pile parc=*p;

    if(*p==NULL)
        printf("Il y'a pas de dossier a deplacer!\n");
    else{
        f.tete = parc;
        while(parc->suivant!=NULL)
            parc = parc->suivant;
        f.queu = parc;
        *p = NULL;
        printf("Deplacement a ete fait avec succes!\n");
    }

    return f;
}

void consulter_file(file f)
{
    if((f.tete==NULL)&&(f.queu==NULL))
        printf("Pas de dossier!\n");
    else
        printf("Le premier dossier:\nNumero: %d\nPriorite: %d\n", f.tete->d.num, f.tete->d.priority);
}

file remove_dossier(file f)
{
    FILE *file;
    struct cellule *done;

    if((f.tete==NULL)&&(f.queu==NULL))
        printf("Pas de dossier!\n");
    else{
        file = fopen("File.txt", "a+");
        if(file == NULL)
            printf("Eror: Memory Struggle! (Creating file)\n");
        else{
            done = f.tete;
            fprintf(file, "Numero: %d  Priorite: %d\n", done->d.num, done->d.priority);
            if(done->suivant!=NULL){
                f.tete = done->suivant;
                free(done);
            }else{
                free(done);
                f = initFile();
            }
        }
        fclose(file);
        printf("Dossier a ete retire avec succes!\n");
    }

    return f;
}
