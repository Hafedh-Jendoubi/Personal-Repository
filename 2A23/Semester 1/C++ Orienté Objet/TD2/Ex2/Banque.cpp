#include "Banque.h"

int Banque::getN()
{
    return n;
}

void Banque::setN(int n)
{
    this->n = n;
}

void Banque::setCompte(Compte c)
{
    this->T[n] = c;
}

bool Banque::rechercher(int RIB)
{
    int i = 0;

    while((RIB != T[i].getRIB()) && (i < n)){
        i++;
    }
    if(i==n)
        return false;
    else
        return true;
}

void Banque::ajouter(Compte c)
{
    T[n]=c;
    n++;
}

void Banque::afficherBanque()
{
    for(int i=0; i<n; i++){
        T[i].afficher();
        cout << endl;
    }
}
