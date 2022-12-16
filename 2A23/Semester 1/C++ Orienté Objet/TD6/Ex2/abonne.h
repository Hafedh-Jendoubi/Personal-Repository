#ifndef ABONNE_H_INCLUDED
#define ABONNE_H_INCLUDED
#include "ouvrage.h"

class Abonne{
  private:
    int num;
    string nom;
    int abonnement;
    string titre;
  public:
    Abonne();
    Abonne(int, string, int, string);
    ~Abonne() {};
    int getNum() {return num;};
    void setTitre(string x){titre = x;};
    string getTitre(){return titre;};
    void afficher();
};

#endif // ABONNE_H_INCLUDED
