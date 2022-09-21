#include "Article.h"

void Article::saisir()
{
    cout << "Reference: "; cin >> refer;
    cout << "Designation: "; cin >> desi;
    cout << "Prix HT: "; cin >> prix;
}

void Article::afficher()
{
    cout << "Article 1:" << endl << "Reference: " << refer << endl;
    cout << "Designation: " << desi << endl << "Prix HT: " << prix << endl;
}

float Article::prix_ttc(float tva)
{
    return prix + prix*(tva/100);
}
