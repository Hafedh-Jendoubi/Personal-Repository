#include "courant.h"

Courant::Courant()
{
    seuil = -500;
}

Courant::Courant(int a, float b, float c):Compte(a, b)
{
    seuil = c;
}

void Courant::afficher()
{
    Compte::afficher();
    cout << "Seuil: " << seuil << endl;
}

