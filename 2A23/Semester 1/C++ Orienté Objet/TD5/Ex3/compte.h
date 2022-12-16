#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED
#include <iostream>
using namespace std;

class Compte{
  protected:
    int RIB;
    float solde;
  public:
    Compte();
    Compte(int, float);
    ~Compte() {};
    void deposer(float);
    void retirer(float);
    void afficher();
};

#endif // COMPTE_H_INCLUDED
