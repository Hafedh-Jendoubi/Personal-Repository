#ifndef BANQUE_H_INCLUDED
#define BANQUE_H_INCLUDED
#include "Compte.h"

class Banque{
private:
    Compte T[50];
    int n;
public:
    int getN();
    void setN(int);
    void setCompte(Compte);
    bool rechercher(int);
    void ajouter(Compte);
    void afficherBanque();
};

#endif // BANQUE_H_INCLUDED
