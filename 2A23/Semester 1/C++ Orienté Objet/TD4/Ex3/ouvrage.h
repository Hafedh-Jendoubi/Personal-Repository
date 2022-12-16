#ifndef OUVRAGE_H_INCLUDED
#define OUVRAGE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Ouvrage{
  private:
    int code;
    string titre;
    int nmb_exemp;
    float prix;
  public:
    Ouvrage();
    Ouvrage(int, string, int, float);
    ~Ouvrage() {};
    int getCode() {return code;};
    void setCode(int code) {this->code = code;};
    string getTitre() {return titre;};
    void setTitre(string titre) {this->titre = titre;};
    int getExp() {return nmb_exemp;};
    void setExp(int nmb_exemp) {this->nmb_exemp = nmb_exemp;};
    float getPrix() {return prix;};
    void setPrix(float prix) {this->prix = prix;};
    void afficher();
    float totalOuvrage() {return nmb_exemp*prix;};
};

#endif // OUVRAGE_H_INCLUDED
