#ifndef OUVRAGE_H_INCLUDED
#define OUVRAGE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Ouvrage{
  protected:
    string titre;
    string date;
    bool exist;
  public:
    Ouvrage();
    Ouvrage(string, string, bool);
    virtual ~Ouvrage() {};
    virtual void afficher();
    string getTitre() const {return titre;};
    bool getInd(){return exist;};
    void setInd(bool x){exist = x;};
};

#endif // OUVRAGE_H_INCLUDED
