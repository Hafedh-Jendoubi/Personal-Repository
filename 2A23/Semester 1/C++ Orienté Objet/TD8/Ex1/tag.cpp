#include "tag.h"

Tag::Tag()
{
    nom = "";
}

Tag::Tag(int a, string b, string c, string d, string e):Note(a, b, c, d)
{
    nom = e;
}

void Tag::afficher()
{
    Note::afficher();
    cout << "Nom: " << nom << endl;
}
