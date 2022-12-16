#ifndef C_COURANT_H_INCLUDED
#define C_COURANT_H_INCLUDED
#include "compte.h"

class C_Courant: public Compte{
  private:
    float seuil;
  public:
    C_Courant();
    C_Courant(int, float, float);
    ~C_Courant() {};
    void afficher();
};

#endif // C_COURANT_H_INCLUDED
