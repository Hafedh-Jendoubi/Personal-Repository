#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[10];
    char prenom[10];
    int age;
}personne;

int main()
{
    int i, n, m;
    personne *tab;

    printf("Taper le nombre des personnes: "); scanf("%d", &n);
    tab = (personne*) malloc(n*sizeof(personne));
    if(tab == NULL){
        printf("EROR: Invalid memory space\n");
        exit(1);
    }else{
        for(i=0; i<n; i++){
            printf("Personne n%d:\nNom: ", i+1); scanf("%s", tab[i].nom);
            printf("Prenom: "); scanf("%s", tab[i].prenom);
            printf("Age: "); scanf("%d", &tab[i].age);
        }
        printf("Remplissage termine!\n");
        for(i=0; i<n; i++){
            printf("Nom: %s  Prenom: %s  Age: %d\n", tab[i].nom, tab[i].prenom, tab[i].age);
        }
    }
    printf("Taper le nombre de personnes a ajouter: "); scanf("%d", &m);
    tab = (personne*) realloc(tab, (n+m)*sizeof(personne));
    if(tab==NULL){
        printf("EROR: Invalid memory space\n");
        exit(1);
    }else{
        for(i=n; i<n+m; i++){
            printf("Personne n%d:\nNom: ", i+1); scanf("%s", tab[i].nom);
            printf("Prenom: "); scanf("%s", tab[i].prenom);
            printf("Age: "); scanf("%d", &tab[i].age);
        }
        printf("Remplissage termine!\n");
        for(i=0; i<n+m; i++){
            printf("Nom: %s  Prenom: %s  Age: %d\n", tab[i].nom, tab[i].prenom, tab[i].age);
        }
    }

    return 0;
}
