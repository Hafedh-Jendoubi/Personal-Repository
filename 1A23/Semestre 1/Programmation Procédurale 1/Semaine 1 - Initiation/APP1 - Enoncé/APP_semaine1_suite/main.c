#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,p;

    printf("Taper la valeur de l'entier x\n");
    scanf("%d", &x);
    printf("Taper la valeur de l'entier y\n");
    scanf("%d", &y);
    printf("La valeur de %d - %d = %d\n", x, y, x-y);

    p = x;
    x = y;   // Permutation des valeurs
    y = p;

    printf("La valeur de %d - %d = %d\n", x, y, x-y);

}
