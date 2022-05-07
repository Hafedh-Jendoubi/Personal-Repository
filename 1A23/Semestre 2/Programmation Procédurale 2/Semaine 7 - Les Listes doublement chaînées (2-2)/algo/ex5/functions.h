#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char nom[20];
    char serie[20];
    char theme[20];
}ep;

typedef struct Cellule{
    ep e;
    struct Cellule *next;
    struct Cellule *back;
}cellule;

typedef struct ListDC{
    cellule *head;
    cellule *tail;
}LD;

void menu(int *ch);

void initLDC(LD *l);
int emptyCheck(LD l);
void showPlaylist(LD l);
void saisirEpisode(ep *e);
void AjoutEpisode(LD *l, ep e);
void afficherEpisode(ep e);
int Serie_Episode(LD l, char s[]);
int Theme_episode(LD l);

#endif // FUNCTIONS_H_INCLUDED