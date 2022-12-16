#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED
#include <vector>
#include <typeinfo>
#include "ouvrage.h"
#include "livre.h"
#include "video.h"
#include "abonne.h"

class Biblio{
  private:
    vector<Ouvrage*> O;
    vector<Abonne> A;
  public:
    Biblio() {}; // This is important because you can't add Biblio(const Biblio&) and Biblio& operator=(); only if you add
    Biblio(const Biblio&);
    Biblio& operator=(const Biblio&);
    ~Biblio();
    vector<Ouvrage*>::iterator getOuvrage(string);
    void ajoutOuvrage(Ouvrage &);
    void ajoutOuvrage(Livre &);
    void ajoutOuvrage(Video &);
    void supprimerOuvrage(string);
    vector<Abonne>::iterator getAbonne(int);
    void ajoutAbonne(Abonne);
    void emprunter(string, int);
    void rendre(int);
    void info();
    void livreAuteur(string);
    string getAuteur();
};

#endif // BIBLIO_H_INCLUDED
