#include "ouvrage.h"

Ouvrage::Ouvrage()
{
    code = 0;
    titre = "";
    nb_exp = 0;
    prix = 0;
}

Ouvrage::Ouvrage(int code, string titre, int nb_exp, float prix)
{
    this->code = code;
    this->titre = titre;
    this->nb_exp = nb_exp;
    this->prix = prix;
}

void Ouvrage::afficher()
{
    cout << "Code: " << code << endl;
    cout << "Titre: " << titre << endl;
    cout << "Nombre de Exemplaire: " << nb_exp << endl;
    cout << "Prix Unitaire: " << prix << endl;
}
