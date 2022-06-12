#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A = 1, B = 2, C = 3, *P1 = NULL, *P2 = NULL;

    //printf("*P1 = %d\n", *P1)  ** On ne peut pas afficher une adresse NULL, "Program bugs!" **
    P1 = &A;
    printf("P1 = %p\n", P1);
    P2 = &C;
    printf("P2 = %p\n", P2);
    *P2 = (*P1)++;
    printf("*P2 = %d\n", *P2);
    P1 = P2;
    printf("P1 = %p\n", P1);
    P2 = &B;
    printf("P2 = %p\n", P2);
    *P1 -= *P2;
    printf("*P1 = %d\n", *P1);
    ++*P2;
    printf("*P2 = %d\n", *P2);
    *P1*=*P2;
    printf("*P1 = %d\n", *P1);

    return 0;
}
