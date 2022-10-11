#include "etudiant.h"

Etudiant::Etudiant()
{
    nom = "";
    adresse = "";
    classe = "";
    date = "";
    num = 0;
}

Etudiant::Etudiant(string a, string b, string c, string d, int e)
{
    nom = a;
    adresse = b;
    classe = c;
    date = d;
    num = e;
}

void Etudiant::afficher()
{
    cout << nom << endl;
    cout << adresse << endl;
    cout << classe << endl;
    cout << date << endl;
    cout << num << endl;
}
