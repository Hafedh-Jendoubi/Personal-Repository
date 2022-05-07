#include <stdio.h>
#include <stdlib.h>

int max(int a, int b);
int min(int a, int b);

int main()
{
    int x, y, z, t, mi1, mi2, minAbs;

    printf("Donner 4 entiers: "); scanf("%d %d %d %d", &x, &y, &z, &t);

    mi1 = min(x, y);
    mi2 = min(z, t);
    minAbs = min(mi1, mi2);

    printf("Le minimum de %d, %d, %d et %d est %d\n", x, y, z, t, minAbs);
    printf("Le maximum de %d, %d, %d et %d est %d\n", x, y, z, t, max(max(x,y), max(z,t)));

    return 0;
}

int min(int a, int b){
    int min;

    if(a<b){
        min = a;
    }else{
        min = b;
    }
}

int max(int a, int b){
    int max;

    if(a<b){
        max = b;
    }else{
        max = a;
    }
}
