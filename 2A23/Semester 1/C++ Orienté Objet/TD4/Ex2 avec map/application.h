#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <map>
#include "evenement.h"

class Application{
  private:
    map<int, Evenement> m;
    int n=0;
  public:
    void ajouter(Evenement);
    void afficher(int);
};

#endif // APPLICATION_H_INCLUDED
