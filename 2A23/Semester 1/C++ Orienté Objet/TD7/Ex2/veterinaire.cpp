#include "veterinaire.h"

Veterinaire::Veterinaire()
{
    id = 0;
    nom = "";
    prenom = "";
}

Veterinaire::Veterinaire(int a, string b, string c)
{
    id = a;
    nom = b;
    prenom = c;
}
