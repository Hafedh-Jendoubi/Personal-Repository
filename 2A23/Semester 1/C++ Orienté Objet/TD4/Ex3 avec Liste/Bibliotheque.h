#ifndef BIBLIOTHEQUE_H_INCLUDED
#define BIBLIOTHEQUE_H_INCLUDED
#include "ouvrage.h"
#include <list>

class Bibilotheque{
  private:
    list<Ouvrage> l;
  public:
    void afficher();
    float prixTotal();
    list<Ouvrage>::iterator rechercher(int);
    void ajouter(Ouvrage);
    void diminuer(int, int);
    void augmenter(int, int);
};

#endif // BIBLIOTHEQUE_H_INCLUDED
