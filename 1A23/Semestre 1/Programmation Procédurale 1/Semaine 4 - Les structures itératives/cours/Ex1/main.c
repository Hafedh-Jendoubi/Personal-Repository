#include <stdio.h>

int main()
{
    int x, i, res=1;

    printf("Entrez un entier naturel: "); scanf("%d", &x);
        for(i=1; i<=x; i++)
            res = res * i;
            printf("%d!=%d\n", x, res);

    return 0;
}
