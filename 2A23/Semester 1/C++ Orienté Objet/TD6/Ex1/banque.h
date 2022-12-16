#ifndef BANQUE_H_INCLUDED
#define BANQUE_H_INCLUDED
#include <vector>
#include <typeinfo>
#include "compte.h"
#include "courant.h"
#include "epargne.h"

class Banque{
  public:
    string nom;
    string lieu;
    vector<Compte*> T;
  public:
    Banque();
    Banque(string, string);
    Banque(const Banque&);
    Banque& operator=(const Banque&);
    ~Banque();
    vector<Compte*>::iterator rechercher(int);
    void ajouter(const Epargne &);
    void ajouter(const Courant &);
    void afficher();
};

#endif // BANQUE_H_INCLUDED
