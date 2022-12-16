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
    int getRIB() const{return RIB;}; //Il faut ajouter cette "const" pour eviter l'erreur dans banque.cpp dans rechercher(e.getRIB())
    float getSolde() {return solde;};
    void deposer(float);
    void retirer(float);
    virtual void afficher();
};

#endif // COMPTE_H_INCLUDED
