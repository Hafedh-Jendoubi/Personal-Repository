#ifndef ZOO_H_INCLUDED
#define ZOO_H_INCLUDED
#include "animal.h"
#include "veterinaire.h"
#include "lion.h"

class Zoo{
  private:
    string adresse;
    vector<Veterinaire> V;
    vector<Animal*> A;
  public:
    Zoo();
    Zoo(string);
    ~Zoo(){};
    vector<Animal*>::iterator chercherAnimal(int);
    void ajouterAnimal(const Animal&);
    void ajouterLion(const Lion&);
    void afficher();
    void ajouterDateVaccin(int, string);
    vector<Veterinaire>::iterator chercherVeterinaire(int);
    void ajouterVeterinaire(const Veterinaire&);
    void affecterAnimal(const Animal&, const Veterinaire&);
};

#endif // ZOO_H_INCLUDED
