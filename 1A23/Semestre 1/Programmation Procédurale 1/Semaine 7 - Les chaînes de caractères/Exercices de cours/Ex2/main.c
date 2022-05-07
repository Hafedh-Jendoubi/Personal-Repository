#include <stdio.h>

int main()
{
    char CH1[100];
    int LongChaine1;

    printf("Introduisez la chaine de caracteres : ");
    gets(CH1);

    for(LongChaine1=0; CH1[LongChaine1]!='\0'; LongChaine1++);
    printf("\nLa longeur de la chaine \"%s\" est %d", CH1, LongChaine1);

    return 0;
}
