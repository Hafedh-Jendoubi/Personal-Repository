#ifndef ARTICLE_H_INCLUDED
#define ARTICLE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Article{
public:
    int refer;
    string desi;
    float prix;

    void saisir();
    void afficher();
    float prix_ttc(float);
};

#endif // ARTICLE_H_INCLUDED
