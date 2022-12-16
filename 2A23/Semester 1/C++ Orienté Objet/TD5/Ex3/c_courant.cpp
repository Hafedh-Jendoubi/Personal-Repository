#include "c_courant.h"

C_Courant::C_Courant()
{
    seuil = -500;
}

C_Courant::C_Courant(int a, float b, float c):Compte(a, b)
{
    seuil = c;
}

void C_Courant::afficher()
{
    Compte::afficher();
    cout << "Seuil: " << seuil << endl;
}
