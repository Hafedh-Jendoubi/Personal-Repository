#ifndef ABONNE_H_INCLUDED
#define ABONNE_H_INCLUDED
#include <iostream>
using namespace std;

class Abonne{
  private:
    string nom;
    string prenom;
    int num;
    int CIN;
    float solde;
  public:
    int getCIN();
    void setCIN(int);
    float getSolde();
    void setSolde(float);
    void saisir();
    void afficher();
    void recharger(float);
    bool consommer(int, float);
};

#endif // ABONNE_H_INCLUDED
