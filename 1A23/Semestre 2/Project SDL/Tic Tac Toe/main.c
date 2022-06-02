#include "tic.h"
#include "image.h"
#include "text.h"

int main(int argc, char **argv[])
{
//Initialisation	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
	TTF_Init();

//Variables declaration
	SDL_Surface *s=NULL;
	tic t;
	int x, y, i;
	SDL_Event e;
	image bg;
	text te;
	int done=1;

//Initialisation des variables
	initBg(&bg); initialiserTic(&t); initText(&te);

//Setting up Screen
	s = SDL_SetVideoMode(1000, 500, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
	if(!s){
		printf("Unable to set 1000x500 video: %s\n", SDL_GetError());
		return 1;
	}
	SDL_WM_SetCaption("Tic Tac Toe", NULL);  //Set Name & Icon of the Window

//Game Loop
	while(done!=0){
		SDL_Flip(s); SDL_PollEvent(&e);
		if(e.type == SDL_QUIT)
			done = 0;
		afficherBack(bg, s); afficherTic(t, s);
		if(t.tour<9 && atilganer(t.tabsuivi)==0){
			if((t.tour+t.joueur)%2 == 0){
				calcul_coup(t.tabsuivi);
				t.tour++;
			}else{
				SDL_WaitEvent(&e);
				if(e.type == SDL_MOUSEBUTTONDOWN){
					if(t.tabsuivi[clicks(e)] == 0){ //This condition is used to avoid cheating, cause player can click and change any filled case and change it
						t.tabsuivi[clicks(e)] = -1;
						t.tour++;
					}
				}
			}
		}else{
			Resultat(t.tabsuivi, s, te);
		}
	}

	terminer(t);
	return 0;
}
