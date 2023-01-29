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
    int getID() const {return id;};
    void afficher();
    vector<int>::iterator chercherAnimal(int);
    void affecter(int);
    vector<int> operator+=(const Veterinaire&);
};

#endif // VETERINAIRE_H_INCLUDED
