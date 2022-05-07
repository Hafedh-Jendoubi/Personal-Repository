#include <stdio.h>

int main()
{
    int i, m, n, k=0, T[50];

    //Remplissage du Tableau:
    do{
    printf("Taper la taille du tableau: "); scanf("%d", &n);
    }while(n<=0);
    for(i=0; i<n; i++){
        printf("Remplissez T[%d] = ", i);
        scanf("%d", &T[i]);
    }

    //Affichage du Tableau:
    for(i=0; i<n; i++)
        printf("%d | ", T[i]);

    if(T[k]==T[k+1]){

    }

    return 0;
}
