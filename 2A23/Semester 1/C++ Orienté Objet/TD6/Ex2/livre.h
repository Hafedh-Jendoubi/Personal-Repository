#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
#include "ouvrage.h"

class Livre: public Ouvrage{
  private:
    string auteur;
  public:
    Livre();
    Livre(string, string, bool, string);
    ~Livre() {};
    void afficher();
    string getAuteur(){return auteur;};
};

#endif // LIVRE_H_INCLUDED
