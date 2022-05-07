#include <stdio.h>

int main()
{
    int permis, voiture;

    printf("Taper 1 pour 'Oui' et 0 pour 'Non'\n\n");
    printf("Est-ce que tu as un permis?\n"); scanf("%d", &permis);
    switch (permis){
    case 1: printf("Est-ce que tu as une voiture?\n"); scanf("%d", &voiture);
            switch(voiture){
            case 1: printf("Conduis moi a la gare\n"); break;
            case 0: printf("Pas de voiture\n"); break;
            default: printf("Mal reponse\n"); break;
            }
    case 0: printf("Est-ce que tu as une voiture?\n"); scanf("%d", &voiture);
            switch(voiture){
            case 1: printf("Hors la loi\n"); break;
            case 0: printf("Vive le velo\n"); break;
            default: printf("Mal reponse\n"); break;
            }
    default: printf("Mal reponse\n"); break;
    }
    return 0;
}
