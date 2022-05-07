#include <stdio.h>

int main()
{
    char aux, ch1[100], ch2[100];
    int LongChaine1, i, j;

    printf("Introduisez la chaine de caracteres : "); gets(ch1);

    for(LongChaine1=0; ch1[LongChaine1]!='\0'; LongChaine1++);

    //1ere methode:
    for(i=0, j=LongChaine1-1; i<LongChaine1; i++, j--)
        ch2[i] = ch1[j];
    ch2[i]='\0';
    printf("\n1ere methode: %s\n", ch2);

    //2eme methode:
    for(i=0, j=LongChaine1-1; i<j; i++, j--){
        aux = ch1[i];
        ch1[i] = ch1[j];
        ch1[j] = aux;
    }
    printf("2eme methode: %s\n", ch2);

    return 0;
}
