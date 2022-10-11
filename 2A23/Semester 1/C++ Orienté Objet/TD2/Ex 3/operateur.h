#ifndef OPERATEUR_H_INCLUDED
#define OPERATEUR_H_INCLUDED
#include <iostream>
#include "abonne.h"
using namespace std;

//No clue about the methods so I will add a CRUD (Create, Read, Update, Delete) Functions.

class Operateur{
  private:
    Abonne Tab[50]; //50 Abonnées
  public:
    void init_tab();
    void ajouter(Abonne);
    void afficher_list();
    void modifier_solde(int);
    void suppr(int);
};

#endif // OPERATEUR_H_INCLUDED
