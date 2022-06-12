#include <stdio.h>

struct date{
int j, m, a;
};

struct P{
char nom[30], prenom[30], matricule[5];
struct date;
};

int main()
{
    struct date an;
    struct P P1;

    printf("Taper votre nom: "); scanf("%s", P1.nom);
    printf("Taper votre prenom: "); scanf("%s", P1.prenom);
    printf("Taper le jour de votre anniversaire: "); scanf("%d", &an.j);
    printf("Taper le mois de votre anniversaire: "); scanf("%d", &an.m);
    printf("Taper l'annee de votre anniverssaire: "); scanf("%d", &an.a);
    printf("Taper votre matricule: "); scanf("%s", P1.matricule);

    printf("\n\n-Nom: %s\n-Prenom: %s\n-Date de naissance: %d/%d/%d\n-Matricule: %s\n", P1.nom, P1.prenom, an.j, an.m, an.a, P1.matricule);

    return 0;
}
