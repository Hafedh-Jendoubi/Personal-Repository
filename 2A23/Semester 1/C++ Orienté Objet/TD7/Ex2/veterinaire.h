#ifndef VETERINAIRE_H_INCLUDED
#define VETERINAIRE_H_INCLUDED
#include "animal.h"

class Veterinaire{
  private:
    int id;
    string nom;
    string prenom;
    vector<int> T;
  public:
    Veterinaire();
    Veterinaire(int, string, string);
    ~Veterinaire(){};
    int getID(){return id;};
};

#endif // VETERINAIRE_H_INCLUDED
