#include "article.h"

Article::Article()
{
    nom = "";
    prix = 0;
    tva = 0;
}

Article::Article(string nom, double prix, double tva)
{
    this->nom = nom;
    this->prix = prix;
    this->tva = tva;
}

void Article::afficher()
{
    cout << "Nom: " << nom << endl;
    cout << "Prix: " << prix << endl;
    cout << "TVA: " << tva << endl;
}
