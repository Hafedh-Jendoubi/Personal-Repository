#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numero;
    char nom[20], prenom[20];
    int age;
    char classe[5];
}etudiant;

void permuterChaines(char a[], char b[])
{
    char c[20] = "";

    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
}

void saisir_etudiant(etudiant e[], int *n)
{
    printf("\nNumero: "); scanf("%d", &e[(*n)].numero);
    printf("Nom: "); fflush(stdin); gets(e[(*n)].nom);
    printf("Prenom: "); fflush(stdin); gets(e[(*n)].prenom);
    printf("Age: "); scanf("%d", &e[(*n)].age);
    printf("Classe: "); fflush(stdin); gets(e[(*n)].classe);
    printf("Etudiant ajoute avec succes!\n");
    (*n)++;
}

void identifier(etudiant e[], int n, int *ne1, int *ne2)
{
    int i;

    printf("Taper le numero du premier etudiant: "); scanf("%d", &(*ne1));
    printf("Taper le numero du premier etudiant: "); scanf("%d", &(*ne2));
    for(i=0; i<n; i++)
        if((*ne1) == e[i].numero){
            (*ne1) = i;
            break;
        }
    for(i=0; i<n; i++)
        if((*ne2) == e[i].numero){
            (*ne2) = i;
            break;
        }
}

void permuter_etudiants1(etudiant e[], int n)
{
    int ne1, ne2;

    identifier(e, n, &ne1, &ne2);
    permuterChaines(e[ne1].classe, e[ne2].classe);
    printf("Classe d'etudiant 1: "); puts(e[ne1].classe);
    printf("Classe d'etudiant 2: "); puts(e[ne2].classe);
}

void permuter_etudiants2(etudiant e[], int n)
{
    char c[20] = "";
    int ne1, ne2, i;

    identifier(e, n, &ne1, &ne2);
    strcpy(c, e[ne1].classe);
    strcpy(e[ne1].classe, e[ne2].classe);
    strcpy(e[ne2].classe, c);
    printf("Classe d'etudiant 1: %s\n", e[ne1].classe);
    printf("Classe d'etudiant 2: %s", e[ne2].classe);
}

void get_imin_imax(etudiant e[], int n)
{
    int i, min, max, imin, imax;

    min = e[0].age; max = e[0].age;
    for(i=1; i<n; i++){
        if(e[i].age<min){
            min = e[i].age;
            imin = i;
        }
        if(e[i].age>max){
            max = e[i].age;
            imax = i;
        }
    }
    printf("L'etudiant le plus agee est d'indice %d ayant l'age %d.\n", imax, max);
    printf("L'etudiant le moins agee est d'indice %d ayant l'age %d.\n", imin, min);
}

int main()
{
    int ch, n=0;
    char a[20], b[20];
    etudiant e[30];

    printf("~~~~~~~~~~ Menu: ~~~~~~~~~~\n");
    printf("0- Exit\n");
    printf("1- Permuter les contenu de deux variables\n"); //Pour tester cette fonction!
    printf("2- Saisir un etudiant\n");
    printf("3- Permuter les classes de deux etudiants (Version 1)\n");
    printf("4- Permuter les classes de deux etudiants (Version 2)\n");
    printf("5- Renvoyer les indices des etudiants ayant l'age min et max\n");

    do{
        do{
            printf("\nTaper votre choix: "); scanf("%d", &ch);
        }while((ch<0)||(ch>5));

        switch(ch){
            case 0: printf("...\n"); break;

            case 1: printf("Taper la chaine 1: "); fflush(stdin); gets(a);
                    printf("Taper la chaine 2: "); fflush(stdin); gets(b);
                    permuterChaines(a, b);
                    printf("Chaine 1: %s\n", a); printf("Chaine 2: %s\n", b);
                    break;

            case 2: saisir_etudiant(e, &n); break;

            case 3: permuter_etudiants1(e, n); break;

            case 4: permuter_etudiants2(e, n); break;

            case 5: get_imin_imax(e, n); break;
        }
    }while(ch!=0);

    return 0;
}
