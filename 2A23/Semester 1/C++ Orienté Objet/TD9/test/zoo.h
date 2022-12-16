#ifndef ZOO_H_INCLUDED
#define ZOO_H_INCLUDED
#include "medecin.h"
#include "animal.h"
#include "lion.h"
#include <typeinfo>

class Zoo{
  private:
    string adr;
    vector<Animal*> T1;
    vector<Medecin> T2;
  public:
    Zoo();
    Zoo(string);
    Zoo(const Zoo&);
    Zoo& operator=(const Zoo&);
    ~Zoo();
    vector<Animal*>::iterator rechercher(string);
    void ajouter(const Animal&); //Monsieur yheb fazet el const rahou!
    void ajouter(const Lion&);
    void ajouterDate(string, string);
    vector<Medecin>::iterator rechercher(int);
    void ajouter(const Medecin&);
};

#endif // ZOO_H_INCLUDED
