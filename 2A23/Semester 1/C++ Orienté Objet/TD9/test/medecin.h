#ifndef MEDECIN_H_INCLUDED
#define MEDECIN_H_INCLUDED
#include "animal.h"

class Medecin{
  private:
    int id;
    string nom;
    string prenom;
    vector<string> A;
  public:
    Medecin();
    Medecin(int, string, string);
    ~Medecin(){};
    int getID() const {return id;};
};

#endif // MEDECIN_H_INCLUDED
