#ifndef HEBERGEMENT_H_INCLUDED
#define HEBERGEMENT_H_INCLUDED
#include <iostream>
using namespace std;

class Hebergement{
  private:
    string adr;
    string nom;
    int nmbr_etoiles;
  public:
    Hebergement();
    Hebergement(string, string, int);
    void setNmbrEtoiles(int);
    int getNmbrEtoiles();
};

#endif // HEBERGEMENT_H_INCLUDED
