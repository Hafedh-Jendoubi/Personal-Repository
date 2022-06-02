#include "text.h"

void initText(text *t)
{
	t->position.x = 15;
	t->position.y = 420;
	//White Color
	t->textColor.r = 255;
	t->textColor.g = 255;
	t->textColor.b = 255;

	t->font = TTF_OpenFont("Font/MENUETTO.TTF", 60);
}

void displayText(text t, SDL_Surface *screen, char ch[])
{
	t.surfaceTexte = TTF_RenderText_Solid(t.font, ch, t.textColor);
	SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}

void freeText(text t)
{
	SDL_FreeSurface(t.surfaceTexte);
}
