#include <stdio.h>
#include <stdlib.h>

void remplir(int T[], int n)
{
    int i;

    for(i=0; i<n; i++){
        printf("T[%d] = ", i+1); scanf("%d", &T[i]);
    }
}

void afficher(int T[], int n)
{
    int i;

    for(i=0; i<n; i++)
        printf("%d | ", T[i]);
    printf("\n");
}

void ajouter(int T[], int *n)
{
    int a;

    printf("Taper l'entier: "); scanf("%d", &a);
    T[(*n)] = a;
    (*n)++;
    printf("Ajout avec succes!\n");
}

void chercher(int T[], int n, int *pos)
{
    int a, k=0, trouve=0;

    printf("Taper l'element a chercher: "); scanf("%d", &a);
    while((k<n)&&(trouve==0)){
        if(T[k]==a){
            trouve = 1;
            (*pos) = k;
        }else
            k++;
    }
    if(trouve==0)
        (*pos) = -2;
}

void modifier_prem_occ(int T[], int n)
{
    int a, k=0, trouve=0;

    printf("Taper l'element a changer: "); scanf("%d", &a);
    while((k<n)&&(trouve==0)){
        if(T[k]==a){
            trouve = 1;
            printf("Taper le nouveau element: "); scanf("%d", &T[k]);
        }else
            k++;
    }
    if(trouve==0)
        printf("Votre element n'existe pas\n");
    else
        printf("Element change avec succes!\n");
}

void modifier_tous_occ(int T[], int n)
{
    int i, a;

    printf("Taper l'element a changer: "); scanf("%d", &a);
    for(i=0; i<n; i++)
        if(T[i]==a){
            printf("Taper le nouveau element: "); scanf("%d", &T[i]);
        }
}

void supprimer_prem_occ(int T[], int *n)
{
    int a, i, j;

    printf("Taper l'element a supprimer: "); scanf("%d", &a);
    for(i=0; i<(*n); i++){
        if(T[i]==a){
            for(j=i; j<(*n)-1; j++)
                T[j] = T[j+1];
        }
    }
    (*n)--;
    printf("Premier element supprimee avec succes!\n");
}

void supprimer_tous_occ(int T[], int *n)
{
    int a, i, j, k=0;

    printf("Taper l'element a supprimer: "); scanf("%d", &a);
    for(i=0; i<(*n); i++){
        if(T[i]==a){
            k++;
            for(j=i; j<(*n)-1; j++)
                T[j] = T[j+1];
        }
    }
    (*n) = (*n) - k;
    printf("Tous les elements ont ete supprimees avec succes!\n");
}

int main()
{
    int n, ch, T[50], pos;

    printf("Taper la taille du tableau: "); scanf("%d", &n);
    system("cls");

    printf("~~~~~~~~ Menu: ~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Remplir le tableau\n");
    printf("2- Afficher le tableau\n");
    printf("3- Ajouter un element au tableau\n");
    printf("4- Chercher un element dans le tableau\n");
    printf("5- Modifier la premiere occurence d'un element\n");
    printf("6- Modifier tous les occurences d'un element\n");
    printf("7- Supprimer la premiere occurence d'un element\n");
    printf("8- Supprimer tous les occurences d'un element\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>8));
        switch(ch){
            case 0:
                printf("...\n"); break;

            case 1:
                remplir(T, n); break;

            case 2:
                afficher(T, n); break;

            case 3:
                ajouter(T, &n); break;

            case 4:
                chercher(T, n, &pos); printf("%d\n", pos+1); break;

            case 5:
                modifier_prem_occ(T, n); break;

            case 6:
                modifier_tous_occ(T, n); break;

            case 7:
                supprimer_prem_occ(T, &n); break;

            case 8:
                supprimer_tous_occ(T, &n); break;
        }
    }while(ch!=0);

    return 0;
}
