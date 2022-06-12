#include <stdio.h>
#include <string.h>

int main()
{
    char ch1[20], part[10], mot[10], ch2[20]="";
    int i, j, k, pos, strc, strm;

    printf("Taper une chaine de caractere: "); gets(ch1);
    printf("Taper la partie de cette chaine vous voulez changer: "); gets(part);
    printf("Taper par quelle mot vous voulez la changer: "); gets(mot);

    for(i=0; i<strlen(ch1)+strlen(mot); i++){
        ch2[i] = ch1[i];
        if(ch1[i] == part[0]){
            pos = i;
            k = i;
            for(j=0; j<strlen(mot); j++){
                ch2[k] = mot[j];
                k++;
            }
            break;
        }
    }

    for(i=pos+strlen(part); i<strlen(ch1); i++){
        ch2[k] = ch1[i];
        k++;
    }

    printf("Votre chaine sera : %s", ch2);

    return 0;
}
