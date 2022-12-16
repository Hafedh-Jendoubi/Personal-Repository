#include "ouvrage.h"

Ouvrage::Ouvrage()
{
    titre = "";
    date = "";
    exist = false;
}

Ouvrage::Ouvrage(string a, string b, bool c)
{
    titre = a;
    date = b;
    exist = c;
}

void Ouvrage::afficher()
{
    cout << "Titre: " << titre << endl;
    cout << "Date: " << date << endl;
    cout << "Existe: ";
    if(exist == true)
        cout << "Oui" << endl;
    else
        cout << "Non" << endl;
}
