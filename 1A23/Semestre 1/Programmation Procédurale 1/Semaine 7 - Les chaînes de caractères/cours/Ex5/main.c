#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[20], ch2[20], ch3[20];

    printf("Introduisez la premiere chaine de caracteres : "); gets(ch1);
    printf("Introduisez la deuxieme chaine de caracteres : "); gets(ch2);

    strncpy(ch3, ch1, strlen(ch1)/2);
    strncat(ch3, ch2, strlen(ch2)/2);

    printf("La motie de \%s\" plus la motie de \"%s\" donne \"%s\"\n", ch1, ch2, ch3);

    return 0;
}
