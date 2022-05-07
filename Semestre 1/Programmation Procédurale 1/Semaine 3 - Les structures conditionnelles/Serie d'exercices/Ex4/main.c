#include <stdio.h>

int main()
{
    int a, b, c, min;

    printf("Taper a, b et c: "); scanf("%d %d %d", &a, &b, &c);
    min = a;
    if((c<b)&&(c<a)){
        min = c;}
    else if((b<c)&&(b<a)){
        min = b;}
    printf("Le min entre %d, %d et %d est %d", a, b, c, min);

    return 0;
}
