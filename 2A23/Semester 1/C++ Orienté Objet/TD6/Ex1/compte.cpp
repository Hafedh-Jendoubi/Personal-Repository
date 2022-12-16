#include "compte.h"

Compte::Compte()
{
    RIB = 0;
    solde = 0;
}

Compte::Compte(int RIB, float solde)
{
    this->RIB = RIB;
    this->solde = solde;
}

void Compte::deposer(float x)
{
    this->solde += x;
}

void Compte::retirer(float x)
{
    this->solde -= x;
}

void Compte::afficher()
{
    cout << "RIB: " << RIB << endl;
    cout << "Solde: " << solde << endl;
}
