#include "c_epargne.h"

C_Epargne::C_Epargne()
{
    solde = 5;
    taux = 0;
}

C_Epargne::C_Epargne(int a, float b, float c):Compte(a, b)
{
    taux = c;
}

void C_Epargne::afficher()
{
        Compte::afficher();
        cout << "Taux: " << taux << endl;
}
