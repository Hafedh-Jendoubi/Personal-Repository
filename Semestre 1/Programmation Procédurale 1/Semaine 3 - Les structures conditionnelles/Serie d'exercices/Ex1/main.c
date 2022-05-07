#include <stdio.h>

int main()
{
    float moy;

    printf("Taper la moyenne: "); scanf("%f", &moy);
    if(moy<10)
        printf("Redouble");
    else if(moy<12)
        printf("Passable");
    else if(moy<14)
        printf("Assez bien");
    else if(moy<16)
        printf("Bien");
    else
        printf("Tres bien");

    return 0;
}
