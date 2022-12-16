#include "pratique.h"

Pratique::Pratique()
{
    ind = -1; //-1 signifie pas de quiz et pas de examen
    ex = 0;
}

Pratique::Pratique(int code, int duree, int ind, int ex):Epreuve(code, duree)
{
    this->ind = ind;
    this->ex = ex;
}

void Pratique::afficher()
{
    Epreuve::afficher();
    if(ind == 0)
        cout << "Type: Test" << endl;
    else if(ind == 1)
        cout << "Type: Examen" << endl;
    cout << "Nombre de exercices: " << ex << endl;
}
