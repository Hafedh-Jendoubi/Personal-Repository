#include "ouvrage.h"

Ouvrage::Ouvrage()
{
    code = 0;
    titre = "";
    nmb_exemp = 0;
    prix = 0;
}

Ouvrage::Ouvrage(int code, string titre, int nmb_exemp, float prix)
{
    this->code = code;
    this->titre = titre;
    this->nmb_exemp = nmb_exemp;
    this->prix = prix;
}

void Ouvrage::afficher()
{
    cout << "Code: " << code << endl;
    cout << "Titre: " << titre << endl;
    cout << "Nombre de exemplaires: " << nmb_exemp << endl;
    cout << "Prix Unitaires: " << prix << endl;
}
