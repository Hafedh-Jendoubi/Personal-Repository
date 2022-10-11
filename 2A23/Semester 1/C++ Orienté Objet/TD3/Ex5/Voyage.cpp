#include "Voyage.h"

void Voyage::setHebergement(Hebergement h)
{
    this->h = h;
}

void Voyage::setEtoiles(int nmbr_etoiles)
{
    this->h.setNmbrEtoiles(nmbr_etoiles);
}

int Voyage::getEtoiles()
{
    return h.getNmbrEtoiles();
}
