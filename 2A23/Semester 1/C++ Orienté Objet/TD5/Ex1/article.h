#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Article{
  protected:
    string nom;
    double prix;
    double tva;
  public:
    Article();
    Article(string, double, double);
    ~Article() {};
    double getPrix() {return prix;};
    void setPrix(double prix) {this->prix = prix;};
    double prixFinal() {return prix*(tva/100) + prix;};
    void afficher();
};

#endif // ARTICLE_H_INCLUDED
