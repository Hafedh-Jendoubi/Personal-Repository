#ifndef PRATIQUE_H_INCLUDED
#define PRATIQUE_H_INCLUDED
#include "epreuve.h"

class Pratique: public Epreuve{
  private:
    int ind;
    int ex;
  public:
    Pratique();
    Pratique(int, int, int, int);
    ~Pratique(){};
    int getInd(){return ind;};
    int getEx(){return ex;};
    void setEx(int x){ex = x;};
    void afficher();
};

#endif // PRATIQUE_H_INCLUDED
