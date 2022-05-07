#include <stdio.h>

int main()
{
    int H, Hsup;
    float Salaire, Sbrute;

    printf("Taper le nombre d'heure\n");
    scanf("%d", &H);
    printf("Taper le nombre d'heure supplementaires\n");
    scanf("%d", &Hsup);
    Sbrute = H*3.397 + Hsup*4.322;
    Salaire = Sbrute * 0.978;
    printf("Salaire est %.3f DT\n", Salaire);
}
