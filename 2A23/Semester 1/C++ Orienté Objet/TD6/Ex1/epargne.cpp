#include "epargne.h"

Epargne::Epargne()
{
    solde = 5;
    taux = 0;
}

Epargne::Epargne(int a, float b, float c):Compte(a, b)
{
    taux = c;
}

void Epargne::afficher()
{
        Compte::afficher();
        cout << "Taux: " << taux << endl;
}
