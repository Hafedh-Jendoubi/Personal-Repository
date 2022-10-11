#include "Compte.h"

void Compte::setSolde(float solde)
{
    this->solde = solde;
}

float Compte::getSolde()
{
    return solde;
}

int Compte::getRIB()
{
    return RIB;
}

void Compte::saisir()
{
    cout << "RIB: "; cin >> RIB;
    cout << "Nom Proprietaire: "; cin >> nomProp;
    cout << "Solde: "; cin >> solde;
}

void Compte::afficher()
{
    cout << "RIB: " << RIB << endl << "Nom Proprietaire: " << nomProp << endl << "Solde: " << solde << endl;
}

bool Compte::retirerArgent(float solde)
{
    if(this->solde >= solde){
        this->solde = this->solde - solde;
        return true;
    }else
        return false;
}

void Compte::deposerArgent(float solde)
{
    this->solde = this->solde + solde;
}

void Compte::consulterSolde()
{
    cout << "Votre solde est: " << solde << endl;
}

void Compte::transferer(Compte& c, float solde)
{
    if(retirerArgent(solde))
        c.deposerArgent(solde);
}
