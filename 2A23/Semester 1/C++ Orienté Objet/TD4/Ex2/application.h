#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include "evenement.h"
#include <vector>

class Application{
  private:
    vector<Evenement> T;
  public:
    void ajouter(Evenement E) {T.push_back(E);};
    void afficher(string);
    Evenement nom_evenement(string);
    void regrouper(string);
    void afficher_evenements();
};

#endif // APPLICATION_H_INCLUDED
