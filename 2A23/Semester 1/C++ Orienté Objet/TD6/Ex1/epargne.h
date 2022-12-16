#ifndef EPARGNE_H_INCLUDED
#define EPARGNE_H_INCLUDED
#include "compte.h"

class Epargne: public Compte{
  private:
    float taux;
  public:
    Epargne();
    Epargne(int, float, float);
    ~Epargne() {};
    float calculerInteret() {return taux*solde;};
    void afficher();
};

#endif // C_EPARGNE_H_INCLUDED
