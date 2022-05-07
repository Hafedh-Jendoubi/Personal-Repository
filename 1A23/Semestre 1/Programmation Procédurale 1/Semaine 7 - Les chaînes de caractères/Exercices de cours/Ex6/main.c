#include <stdio.h>
#include <string.h>

int main()
{
    char ch[50], ch1[50]="", test[50]="";
    int i, k;

    printf("Taper votre mot ou chaine de caractere: "); gets(ch);

    k=0;
    for(i=strlen(ch)-1; i>=0; i--){
        if(ch[i]==' '){
            i--;
        }
        test[k] = ch[i];
        k++;
    }

    k=0;
    for(i=0; i<strlen(ch); i++){
        if(ch[i]==' '){
            i++;
        }
        ch1[k] = ch[i];
        k++;
    }

    if(strcmp(ch1, test)==0)
        printf("\"%s\" est un palindrome\n", ch);
    else
        printf("\"%s\" n'est pas un palindrome\n", ch);

    return 0;
}
