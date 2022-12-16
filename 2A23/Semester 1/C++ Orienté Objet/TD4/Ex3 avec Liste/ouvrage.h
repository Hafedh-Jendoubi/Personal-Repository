#ifndef OUVRAGE_H_INCLUDED
#define OUVRAGE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Ouvrage{
  private:
    int code;
    string titre;
    int nb_exp;
    float prix;
  public:
    Ouvrage();
    Ouvrage(int, string, int, float);
    ~Ouvrage() {};
    int getCode() {return code;};
    void setCode(int x) {code = x;};
    string getTitre() {return titre;};
    void setTitre(string ch) {titre = ch;};
    int getExp() {return nb_exp;};
    void setExp(int x) {nb_exp = x;};
    float getPrix() {return prix;};
    void setPrix(float x) {prix = x;};
    void afficher();
    float totalOuvrage() {return prix*nb_exp;};
};

#endif // OUVRAGE_H_INCLUDED
