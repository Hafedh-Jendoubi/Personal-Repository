#include <stdio.h>

int main()
{
    int x;

    printf("Taper un nombre compris entre 1 et 7\n"); scanf("%d", &x);
    switch (x){
    case 1: printf("%d correspond au lundi", x); break;
    case 2: printf("%d correspond au mardi", x); break;
    case 3: printf("%d correspond au mercredi", x); break;
    case 4: printf("%d correspond au jeudi", x); break;
    case 5: printf("%d correspond au vendredi", x); break;
    case 6: printf("%d correspond au samedi", x); break;
    case 7: printf("%d correspond au dimanche", x); break;
    }
    return 0;
}
