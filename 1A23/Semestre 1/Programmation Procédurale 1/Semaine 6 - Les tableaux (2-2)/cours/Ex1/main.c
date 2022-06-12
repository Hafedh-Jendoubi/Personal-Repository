#include <stdio.h>

int main()
{
    int i, j, m, n, min, max, tampon, trouve, milieu, debut, fin, X, t1[50], t2[50], t3[50];

    //Taille de t1 & t2
    do{
        printf("Taper la taille de t1: "); scanf("%d", &m);
    }while((m<=0)||(m>50));
    do{
        printf("Taper la taille de t2: "); scanf("%d", &n);
    }while((n<=0)||(n>50));

    //Remplissage de t1 & t2
    for(i=0; i<m; i++){
        printf("Remplissez t1[%d] : ", i+1);
        scanf("%d", &t1[i]);
    }
    for(i=0; i<n; i++){
        printf("Remplissez t2[%d] : ", i+1);
        scanf("%d", &t2[i]);
    }

    //Affichage des tableaux t1 & t2
    printf("\nTableau t1: \n");
    for(i=0; i<m; i++)
        printf("%d | ", t1[i]);
    printf("\nTableau t2: \n");
    for(i=0; i<n; i++)
        printf("%d | ", t2[i]);

    //Tri du tableau t1
    for (i=0; i<m-1; i++){
        min=i;
        for (j=i+1; j<m; j++){
            if(t1[j]<t1[min])
                min=j;
        }
        tampon=t1[i];
        t1[i]=t1[min];
        t1[min]=tampon;
    }

    //Tri du tableau t2
    for (i=0; i<n-1; i++){
        min=i;
        for (j=i+1; j<n; j++){
            if(t2[j]<t2[min])
                min=j;
        }
        tampon=t2[i];
        t2[i]=t2[min];
        t2[min]=tampon;
    }

    //Affichage de t1 & t2 apres tri
    printf("\n\nTableau t1 ((tri)): \n");
    for(i=0; i<m; i++)
        printf("%d | ", t1[i]);
    printf("\nTableau t2 ((tri)): \n");
    for(i=0; i<n; i++)
        printf("%d | ", t2[i]);

    //Remplissage du tableau t3 avec t1 & t2 et Affichage de t3
    for(i=0; i<m; i++)
        t3[i] = t1[i];
    for(i=m; i<n+m; i++)
        t3[i] = t2[i-m];
    printf("\n\nTableau t3: \n");
    for(i=0; i<n+m; i++)
        printf("%d | ", t3[i]);

    //Tri du tableau t3 dans l'ordre décroissant
    for (i=0; i<n+m-1; i++){
        max=i;
        for (j=i+1; j<n+m; j++){
            if(t3[j]>t3[max])
                max=j;
        }
        tampon=t3[i];
        t3[i]=t3[max];
        t3[max]=tampon;
    }

    //Affichage du tableau t3 apres tri
    printf("\nTableau t3 ((tri a l'ordre decroissant)): \n");
    for(i=0; i<n+m; i++)
        printf("%d | ", t3[i]);

    //Recherche dichotomique dans t3
    printf("\n\nTaper la valeur pour chercher: "); scanf("%d", &X);
    trouve = -1; debut = 0 ; fin = n-1 ;
    while((trouve==-1)&&(debut<=fin)){
        milieu = (debut + fin)/2;
        if(t3[milieu]>X)
            fin=milieu - 1;
        else if(t3[milieu]<X)
            debut = milieu + 1;
        else
            trouve=1;
    }
    if(trouve==-1)
        printf("%d existe dans le tableau\n", X);
    else
        printf("%d n'existe pas dans le tableau\n", X);

    return 0;
}
