#include "functions.h"

void menu(int *ch)
{
    if(*ch == -1){
        printf("~~~~~~~~ Menu: ~~~~~~~~\n");
        printf("1- Show playlist\n");
        printf("2- Add Episodes to your playlist\n");
        printf("3- Test\n");
        printf("0- Exit\n");
    }
    do{
        printf("\nTaper votre choix: "); scanf("%d", &*ch);
    }while((*ch<0)||(*ch>3));
}

void initLDC(LD *l)
{
    l->head = NULL;
    l->tail = NULL;
}

int emptyCheck(LD l)
{
    if(l.tail == NULL && l.head == NULL)
        return 1;
    else
        return 0;
}

void showPlaylist(LD l)
{
    if(emptyCheck(l) == 1)
        printf("Playlist is empty!\n");
    else{
        cellule *parc=l.head;

        while(parc != NULL){
            printf("Episode Name: %s\n", parc->e.nom);
            parc = parc->next;
        }
    }
}

void saisirEpisode(ep *e)
{
    printf("Episode Name: "); fflush(stdin); gets(e->nom);
    printf("Episode Theme: "); fflush(stdin); gets(e->theme);
    printf("Episode Serie: "); fflush(stdin); gets(e->serie);
}

void AjoutEpisode(LD *l, ep e)
{
    cellule *new;

    new = (cellule*) malloc(sizeof(cellule));
    if(new == NULL)
        printf("Eror: Struggle Memory (AjoutEpisode Function)\n");
    else{
        new->e = e;
        new->next = l->head;
        new->back = NULL;
        if(emptyCheck(*l) == 1)
            l->tail = new;
        else
            l->head->back = new;
        l->head = new;
        printf("Episode \"%s\" has been succefully added to playlist.\n", e.nom);
    }
}

void afficherEpisode(ep e)
{
    printf("Episode Name: %s\n", e.nom);
    printf("Episode Theme: %s\n", e.theme);
    printf("Episode Serie: %s\n", e.serie); 
}

int Serie_Episode(LD l, char s[])
{
    cellule *parc=l.head;
    int k=0;

    while(parc != NULL){
        if(strcmp(s, parc->e.serie) == 0)
            k++;
        parc = parc->next;
    }

    return k;
}

int Theme_episode(LD l)
{
    cellule *parc=l.head;
    char t[20][20]; int k, i, trv;

    strcpy(t[0], parc->e.theme); k = 1;
    parc = parc->next;
    while(parc!=NULL){
        trv = 0;
        for(i=0; i<k; i++){
            if(strcmp(parc->e.theme, t[i])==0)
                trv = 1;
        }
        if(trv == 0){
            strcpy(t[k], parc->e.theme); k++;
        }
        parc = parc->next;
    }

    return k;
}