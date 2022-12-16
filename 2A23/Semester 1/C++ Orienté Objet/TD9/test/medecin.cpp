#include "medecin.h"

Medecin::Medecin()
{
    id = 0;
    nom = "";
    prenom = "";
}

Medecin::Medecin(int a, string b, string c)
{
    id = a;
    nom = b;
    prenom = c;
}
