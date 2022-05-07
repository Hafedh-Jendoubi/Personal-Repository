#include <stdio.h>

int main()
{
    int Ninscirt, Npresent;
    float Pourcentage;

    printf("Nombre de candidats inscrit ? "); scanf("%d", &Ninscirt);
    printf("Nombre de candidats inscit = %d\n", Ninscirt);
    printf("Nombre de candidats present ? "); scanf("%d", &Npresent);
    printf("Nombre de candidats present = %d\n", Npresent);
    Pourcentage = ((float)Npresent * 100)/(float)Ninscirt;
    printf("Pourcentage de presence = %.1f %%\n", Pourcentage);

return 0;
}
