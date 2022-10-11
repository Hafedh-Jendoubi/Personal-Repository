#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED
#include <iostream>
using namespace std;

class Compte{
private:
    int RIB;
    string nomProp;
    float solde;
public:
    void setSolde(float);
    float getSolde();
    int getRIB();
    void saisir();
    bool retirerArgent(float);
    void deposerArgent(float);
    void consulterSolde();
    void transferer(Compte &, float);
    // Just to check things out
    void afficher();
};

#endif // COMPTE_H_INCLUDED
