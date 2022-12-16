#include "abonne.h"

Abonne::Abonne()
{
    num = 0;
    nom = "";
    abonnement = 0;
    titre = "";
}

Abonne::Abonne(int a, string b, int c, string d)
{
    num = a;
    nom = b;
    abonnement = c;
    titre = d;
}

void Abonne::afficher()
{
    cout << "ID: " << num << endl;
    cout << "Nom: " << nom << endl;
    cout << "Numero de identification: " << abonnement << endl;
    cout << "Titre: " << titre << endl;
}
