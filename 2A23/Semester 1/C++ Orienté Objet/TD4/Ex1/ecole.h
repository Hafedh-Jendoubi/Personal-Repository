#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED
#include <vector>
#include "etudiant.h"

class Ecole{
  private:
    vector<Etudiant> T;
  public:
    void ajouter(Etudiant);
    void afficher();
    vector <Etudiant>::iterator rechercher(int);
    void supprimer(int);
    void rechercher_afficher(string);
};

#endif // ECOLE_H_INCLUDED
