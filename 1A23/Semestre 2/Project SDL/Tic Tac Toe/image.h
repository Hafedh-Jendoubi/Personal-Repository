#ifndef IMAGE_H
#define IMAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
	SDL_Surface *img;
	SDL_Rect pos1;
	SDL_Rect pos2;
}image;

void initBg(image *bg);
void initY(image *A);
void initN(image *A);
void afficherBack(image p, SDL_Surface *s);
void afficherImg(image A, SDL_Surface *s);
void liberer(image A);

#endif
