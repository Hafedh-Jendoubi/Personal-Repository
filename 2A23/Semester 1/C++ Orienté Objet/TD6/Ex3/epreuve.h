#ifndef EPREUVE_H_INCLUDED
#define EPREUVE_H_INCLUDED
#include <iostream>
using namespace std;

class Epreuve{
  protected:
    int code;
    int duree;
  public:
    Epreuve();
    Epreuve(int, int);
    ~Epreuve(){};
    int getCode(){return code;};
    void setDuree(int x){duree = x;};
    virtual void afficher();
};

#endif // EPREUVE_H_INCLUDED
