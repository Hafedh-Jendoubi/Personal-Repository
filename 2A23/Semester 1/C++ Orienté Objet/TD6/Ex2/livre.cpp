#include "livre.h"

Livre::Livre()
{
    auteur = "";
}

Livre::Livre(string a, string b, bool c, string d):Ouvrage(a, b, c)
{
    auteur = d;
}

void Livre::afficher()
{
    Ouvrage::afficher();
    cout << "Auteur: " << auteur << endl;
}
