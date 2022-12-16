#include "evenement.h"

Evenement::Evenement()
{
    date = 0;
    lieu = "";
    type = "";
    nom = "";
}

Evenement::Evenement(int date, string lieu, string type, string nom)
{
    this->date = date;
    this->lieu = lieu;
    this->type = type;
    this->nom = nom;
}

void Evenement::afficher()
{
    cout << date << ", " << nom << ", " << lieu << ", " << type << endl;
}
