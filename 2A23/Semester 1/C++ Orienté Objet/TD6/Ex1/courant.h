#ifndef COURANT_H_INCLUDED
#define COURANT_H_INCLUDED
#include "compte.h"

class Courant: public Compte{
  private:
    float seuil;
  public:
    Courant();
    Courant(int, float, float);
    ~Courant() {};
    void afficher();
};

#endif // COMPTE_H_INCLUDED
