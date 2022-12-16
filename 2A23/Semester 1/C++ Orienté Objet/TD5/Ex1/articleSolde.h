#ifndef ARTICLESOLDE_H_INCLUDED
#define ARTICLESOLDE_H_INCLUDED
#include "article.h"

class articleSolde: public Article{
  private:
    float percentage;
  public:
    articleSolde();
    articleSolde(string, double, double, float);
    ~articleSolde() {};
    double prixFinal();
    void afficher();
};

#endif // ARTICLESOLDE_H_INCLUDED
