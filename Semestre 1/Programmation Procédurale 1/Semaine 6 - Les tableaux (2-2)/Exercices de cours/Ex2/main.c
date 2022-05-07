#include <stdio.h>

int main()
{
    int i, j, n, x, aux, trouve, T[50];

    do{
    printf("Taper la taille du tableau: "); scanf("%d", &n);
    }while(n<=0);
    printf("Remplissez T[0] = "); scanf("%d", &T[0]);
    for(i=1; i<n; i++){
        do{
            printf("Remplissez T[%d] = ", i); scanf("%d", &T[i]);
        }while(T[i-1]>T[i]);
    }
    printf("\nLe tableau est: \n");
    for(i=0; i<n; i++)
        printf("%d | ", T[i]);
    for(i=1; i<(n/2)+1; i++){
        aux=T[i];
        for (j=i; j<n-i; j++)
            T[j]=T[j+1];
        T[n-i]=aux;
    }
    printf("\nLe tableau TM est: \n");
    for(i=0; i<n; i++)
        printf("%d | ", T[i]);
    printf("\nTaper un entier: "); scanf("%d", &x);
    trouve = 0; i = 0;
    while((trouve==0)&&(i<n)){
        if(T[i]==x)
            trouve = 1;
        else
            i++;
    }
    if(trouve==1)
        printf("\n%d existe dans le tableau!", x);
    else
        printf("\n%d n'existe pas dans le tableau!", x);

    return 0;
}
