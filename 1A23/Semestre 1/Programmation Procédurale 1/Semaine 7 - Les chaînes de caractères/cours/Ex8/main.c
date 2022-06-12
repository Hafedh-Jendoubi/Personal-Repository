#include <stdio.h>
#include <string.h>

int main()
{
    char chaine[5][50];
    int i, j;

    for(i=0; i<5; i++){
        for(j=0; j<50; j++){
            chaine[i][j] = "";
        }
    }

    for(i=0; i<5; i++){
        printf("Remplissez chaine n%d: ", i); gets(chaine[i]);
    }

    for(i=0; i<5; i++){
        printf("La longeur du chaine n%d est: %d\n", i, strlen(chaine[i]));
    }

    return 0;
}
