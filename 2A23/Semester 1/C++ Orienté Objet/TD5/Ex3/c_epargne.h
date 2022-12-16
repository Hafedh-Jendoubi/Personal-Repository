#ifndef C_EPARGNE_H_INCLUDED
#define C_EPARGNE_H_INCLUDED
#include "compte.h"

class C_Epargne: public Compte{
  private:
    float taux;
  public:
    C_Epargne();
    C_Epargne(int, float, float);
    ~C_Epargne() {};
    float calculerInteret() {return taux*solde;};
    void afficher();
};

#endif // C_EPARGNE_H_INCLUDED
