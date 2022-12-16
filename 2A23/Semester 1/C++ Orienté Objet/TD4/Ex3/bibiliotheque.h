#ifndef BIBILIOTHEQUE_H_INCLUDED
#define BIBILIOTHEQUE_H_INCLUDED
#include "ouvrage.h"
#include <vector>

class Bibliotheque{
  private:
    vector<Ouvrage> T;
  public:
    void afficher();
    float prixTotal();
    vector<Ouvrage>::iterator rechercher(int);
    void ajouter(Ouvrage);
    void diminuerNbExp(int, int);
    void augmenterNbExp(int, int);
};


#endif // BIBILIOTHEQUE_H_INCLUDED
