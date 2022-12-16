#include "evenement.h"

Evenement::Evenement()
{
    date = "";
    lieu = "";
    type = "";
    nom = "";
}

Evenement::Evenement(string date, string lieu, string type, string nom)
{
    this->date = date;
    this->lieu = lieu;
    this->type = type;
    this->nom = nom;
}

