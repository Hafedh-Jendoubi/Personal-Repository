#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Etudiant{
    public:
    string nom;
    string prenom;
    float tab_notes[3];

    void saisir();
    void afficher();
    float moy();
    bool admis();
    int exae_quo(Etudiant);
};

#endif // ETUDIANT_H_INCLUDED
