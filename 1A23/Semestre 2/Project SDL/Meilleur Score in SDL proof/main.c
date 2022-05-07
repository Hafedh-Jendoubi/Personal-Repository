#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sauvegarder(char nom[], int score)
{
    FILE *f=NULL;

    f = fopen("scores.txt", "a+");
    if(f==NULL)
        printf("Memory Error!\n");
    else{
        fprintf(f, "Name: %s  Score: %d\n", nom, score);
    }
    fclose(f);
}

void meilleur(char nomfichier[], int *score, char nom[])
{
	FILE *f;
	int scor[20], max, k=0, i, indice=0;
	char nomjoueur[20][20];

	f = fopen(nomfichier, "r");
	if(f == NULL)
		printf("Memory error (meilleur() function in minimap.c)\n");
	else{
		while(!feof(f)){
			fscanf(f, "Name: %s  Score: %d\n", nomjoueur[k], &scor[k]);
			k++;
        }
		max = scor[0];
		for(i=1; i<k; i++){
			if(max < scor[i]){
				max = scor[i];
				indice = i;
			}
		}
		*score = max;
		strcpy(nom, nomjoueur[indice]);
	}
	fclose(f);
}

int main()
{
    int i, score, scor;
    char nom[10], meill[10];

    for(i=0; i<3; i++){
        printf("\n~~ Player number %d: ~~\n", i+1);
        printf("Player Name: "); scanf("%s", nom);
        printf("Score: "); scanf("%d", &score);
        sauvegarder(nom, score);
    }

    meilleur("scores.txt", &scor, meill);
    printf("The best is:\n\tName: %s  Score: %d\n", meill, scor);

    return 0;
}