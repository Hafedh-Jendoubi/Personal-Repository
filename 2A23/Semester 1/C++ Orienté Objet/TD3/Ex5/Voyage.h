#ifndef VOYAGE_H_INCLUDED
#define VOYAGE_H_INCLUDED
#include "Hebergement.h"

class Voyage{
  private:
    int id;
    string vill_org;
    string vill_des;
    string date_dep;
    string date_ret;
    float prix;
    string nom;
    Hebergement h;
  public:
    void setHebergement(Hebergement);
    void setEtoiles(int);
    int getEtoiles();
};

#endif // VOYAGE_H_INCLUDED
