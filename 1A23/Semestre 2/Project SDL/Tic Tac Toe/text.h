#ifndef TEXTE_H
#define TEXTE_H
#include <SDL/SDL_ttf.h>

typedef struct{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surfaceTexte;
	SDL_Color textColor;
	char ch[20];
}text;

void initText(text *t);
void displayText(text t, SDL_Surface *screen, char ch[]);
void freeText(text t);

#endif
