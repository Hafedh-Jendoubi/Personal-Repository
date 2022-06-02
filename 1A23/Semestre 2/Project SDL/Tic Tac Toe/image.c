#include "image.h"

void initBg(image *bg) //Background Initialisation
{
	bg->img = IMG_Load("Tic.png");

	bg->pos1.x = 0;
	bg->pos1.y = 0;
	bg->pos2.x = 0;
	bg->pos2.y = 0;
	bg->pos2.w = 1000;
	bg->pos2.h = 500;
}

void initY(image *A) //Green Image Initialisation
{
	A->img = IMG_Load("Y.png");
	
	A->pos1.x = 0;
	A->pos1.y = 0;
	A->pos2.x = 10;
	A->pos2.y = 10;
	A->pos1.w = 80;
	A->pos1.h = 80;
}

void initN(image *A) //Red Image Initialisation
{
	A->img = IMG_Load("N.png");
	
	A->pos1.x = 0;
	A->pos1.y = 0;
	A->pos2.x = 10;
	A->pos2.y = 10;
	A->pos1.w = 80;
	A->pos1.h = 80;
}

void afficherBack(image p, SDL_Surface *s) //Function to show background on screen 
{
	SDL_BlitSurface(p.img, &p.pos2, s, &p.pos1);
}

void afficherImg(image A, SDL_Surface *s) //Function to show images on screen
{
	SDL_BlitSurface(A.img, &A.pos1, s, &A.pos2);
}

void liberer(image A) //Function to free surfaces
{
	SDL_FreeSurface(A.img);
}
