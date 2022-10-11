#include "Hebergement.h"

Hebergement::Hebergement()
{
    adr = "";
    nom = "";
    nmbr_etoiles = 0;
}

Hebergement::Hebergement(string adr, string nom, int nmbr_etoiles)
{
    this->adr = adr;
    this->nom = nom;
    this->nmbr_etoiles = nmbr_etoiles;
}

void Hebergement::setNmbrEtoiles(int nmbr_etoiles)
{
    this->nmbr_etoiles = nmbr_etoiles;
}

int Hebergement::getNmbrEtoiles()
{
    return nmbr_etoiles;
}
