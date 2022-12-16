#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED
#include <iostream>
using namespace std;
#include <string>

class Evenement{
  private:
    string date;
    string lieu;
    string type;
    string nom;
  public:
    Evenement();
    Evenement(string, string, string, string);
    ~Evenement() {};
    string getDate() {return date;};
    string getNom() {return nom;};
    string getLieu() {return lieu;};
    string getType() {return type;};
};

#endif // EVENEMENT_H_INCLUDED
