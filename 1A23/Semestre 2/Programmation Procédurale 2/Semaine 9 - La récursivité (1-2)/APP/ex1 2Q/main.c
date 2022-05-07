#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromeRec(char c[],int i, int j) {
    if (j == i)
        return 1;
    else if(c[i] == c[j])
        return palindromeRec(c, ++i, --j);
    else
        return 0;
}

int main() {
    char chaine[10];

    printf("Taper un mot: "); scanf("%s", chaine);

    if(palindromeRec(chaine, 0, strlen(chaine)-1)==1)
        printf("%s est un palindrome\n", chaine);
    else
        printf("%s n'est pas un palindrome\n", chaine);
    return 0;
}