#ifndef CLUB_H_INCLUDED
#define CLUB_H_INCLUDED

typedef struct
{
    int identifiant;
    char niveau[2];
}adherent;

typedef struct
{
    char Mat[20];
    int nadherent;
    char type[10];
    adherent TabA[30];
}club;

int chercher_club(club TabC[], int nbC, char Mat[]);
void creer_club(club *C, club TabC[], int nbC);
void ajouter_club(club TabC[], int *nbC, club C);
void afficher_clubs(club TabC[], int nbC);
void saisir_adherent(adherent *A);
void Inscrire_Adherent(club TabC[], int nbC, char Mat[], adherent A);

#endif // CLUB_H_INCLUDED
