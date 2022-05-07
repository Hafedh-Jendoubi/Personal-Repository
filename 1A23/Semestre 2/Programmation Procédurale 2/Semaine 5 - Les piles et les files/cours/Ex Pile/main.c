#include "functions.h"

int main()
{
    char expr[40];

    printf("Taper une chaine de caractere: "); fflush(stdin); gets(expr);
    printf("%d - ([1] Bien Parenthesee / [0] Mal Parenthesee)\n", bien_paranthesee(expr));

    return 0;
}
