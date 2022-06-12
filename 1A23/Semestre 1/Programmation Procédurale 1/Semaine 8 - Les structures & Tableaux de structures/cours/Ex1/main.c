#include <stdio.h>
#include <stdlib.h>

struct point{
    float abs, ord;
};

int main()
{
    struct point P1, P2, PM, PT;
    float dx, dy;

    printf("Saisir l'abs du point P1: ");
    scanf("%f", &P1.abs);
    printf("Saisir l'ord du point P1:");
    scanf("%f", &P1.ord);
    printf("Saisir l'abs du point P2: ");
    scanf("%f", &P2.abs);
    printf("Saisir l'ord du point P2:");
    scanf("%f", &P2.ord);

    printf("\nP1(%.2f, %.2f)\tP2(%.2f, %.2f)\n", P1.abs, P1.ord, P2.abs, P2.ord);

    printf("Taper dx: "); scanf("%f", &dx);
    printf("Taper dy: "); scanf("%f", &dy);

    P1.abs += dx;
    P1.ord += dy;

    printf("\nLes nouveaux cordonnees: P1(%.2f, %.2f)\tP2(%.2f, %.2f)\n", P1.abs, P1.ord, P2.abs, P2.ord);

    PM.abs = (P1.abs + P2.abs)/2;
    PM.ord = (P1.ord + P2.ord)/2;

    printf("\nLe point milieu PM a pour cordonnees: PM(%.2f, %.2f)\n", PM.abs, PM.ord);

    return 0;
}
