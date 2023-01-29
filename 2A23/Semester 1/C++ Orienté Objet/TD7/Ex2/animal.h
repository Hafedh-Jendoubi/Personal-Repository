#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal{
  protected:
    string espece;
    int mat;
    vector<string> D;
  public:
    Animal();
    Animal(string, int);
    ~Animal(){};
    vector<string> getD(){return D;};
    int getMat() const {return mat;};
    virtual void afficher();
    vector<string>::iterator chercherDate(string);
    void ajouterDateVaccin(string x) {D.push_back(x);};
};

#endif // ANIMAL_H_INCLUDED
