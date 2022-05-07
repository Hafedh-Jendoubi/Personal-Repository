#include <stdlib.h>
#include <stdio.h>

//Amazing & simple function. Not mine to be honest!
void binaire(int a)
{
    int reste;
    if(a>0)
    {
        reste=a%2;
        binaire(a/2);
    printf("%d",reste);
    }
 
}

int main()
{
    int a;

    printf("Taper a: "); scanf("%d", &a);
    binaire(a);

    return 0;
}