#include "veterinaire.h"

Veterinaire::Veterinaire()
{
    id = 0;
    nom = "";
    prenom = "";
}

Veterinaire::Veterinaire(int a, string b, string c)
{
    id = a;
    nom = b;
    prenom = c;
}

void Veterinaire::afficher()
{
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    for(vector<int>::iterator it=T.begin(); it!=T.end(); it++)
        cout << " [*] " << *it << endl;
}

vector<int>::iterator Veterinaire::chercherAnimal(int id)
{
    vector<int>::iterator it;
    for(it=T.begin(); it!=T.end(); it++){
        if(*it == id)
            return it;
    }
    return T.end();
}

void Veterinaire::affecter(int id)
{
    vector<int>::iterator it = chercherAnimal(id);
    if(it == T.end())
        T.push_back(id);
    else
        cout << "Animal existe deja." << endl;
}

vector<int> Veterinaire::operator+=(const Veterinaire &v)
{
    in
}
