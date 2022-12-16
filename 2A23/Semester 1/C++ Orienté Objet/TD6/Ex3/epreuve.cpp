#include "epreuve.h"

Epreuve::Epreuve()
{
    code = 0;
    duree = 0;
}

Epreuve::Epreuve(int code, int duree)
{
    this->code = code;
    this->duree = duree;
}

void Epreuve::afficher()
{
    cout << "Code: " << code << endl;
    cout << "Duree: " << duree << " (mins)" << endl;
}
