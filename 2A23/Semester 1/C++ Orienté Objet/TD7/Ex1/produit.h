#ifndef PRODUIT_H_INCLUDED
#define PRODUIT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Produit{
  private:
    int reff;
    string lib;
    int quant;
    float pu;
  public:
    Produit();
    Produit(int, string);
    ~Produit(){};
    void ChangerQuantite(int x){quant = x;};
    void ChangerPrix(float x){pu = x;};
    //Produit operator=(const Produit&);
    Produit operator+(const Produit&);
    friend ostream& operator<<(ostream&, const Produit&);
};

#endif // PRODUIT_H_INCLUDED
