#include <stdio.h>

int main()
{
    int a, b;
    char operateur;

    printf("Taper l'operateur: "); scanf("%c", &operateur);
    printf("Taper a: "); scanf("%d", &a);
    printf("Taper b: "); scanf("%d", &b);
    switch(operateur)
    {
    case '+': printf("%d + %d = %d", a, b, a+b); break;
    case '-': printf("%d - %d = %d", a, b, a-b); break;
    case '*': printf("%d * %d = %d", a, b, a*b); break;
    case '/': printf("%d / %d = %d", a, b, a/b); break;
    case '%': printf("%d %% %d = %d", a, b, a%b); break;
    default : printf("Invalid operateur!");
    }

    return 0;
}
