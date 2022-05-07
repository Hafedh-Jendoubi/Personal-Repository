#include <stdio.h>

int main()
{
    int Ninscrit, Npresent;

    printf("nombre de candidats inscrit ?"); scanf("%d", &Ninscrit);
    printf("\nnombre de candidats inscrit = %d", Ninscrit);
    printf("\nnombre de candidats presents ?"); scanf("%d", &Npresent);
    printf("\nnombre de candidats presents = %d", Npresent);
    printf("\npourcentage de presence = %f %", (Npresent*100)/Ninscrit);
    return 0;
}
