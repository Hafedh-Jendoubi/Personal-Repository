#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Etudiant{
  private:
    string nom;
    string adresse;
    string classe;
    string date;
    int num;
  public:
    Etudiant();
    Etudiant(string, string, string, string, int);
    ~Etudiant() {};
    int getNum() {return num;}
    string getClass() {return classe;}
    void afficher();
};

#endif // ETUDIANT_H_INCLUDED
