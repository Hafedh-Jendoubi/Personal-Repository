#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Animal{
  protected:
    string espece;
    string mat;
    vector<string> D;
  public:
    Animal();
    Animal(string, string);
    ~Animal(){};
    string getMat() const {return mat;}; // Aala khater manesh fel class mtaa animal // Zedna const kodem el getteur aala khater fel Zoo.h fel fonction ajouter() hatina parametere "const Animal &" donc lezm tzid const kodem el getteur
    vector<string>::iterator rechercher(string);
    void ajouterDate(string);
};


#endif // ANIMAL_H_INCLUDED
