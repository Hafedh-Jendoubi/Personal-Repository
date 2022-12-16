#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Evenement{
  private:
    int date;
    string lieu;
    string type;
    string nom;
  public:
    Evenement();
    Evenement(int, string, string, string);
    ~Evenement() {};
    int getDate() {return date;};
    void afficher();
};

#endif // EVENEMENT_H_INCLUDED
