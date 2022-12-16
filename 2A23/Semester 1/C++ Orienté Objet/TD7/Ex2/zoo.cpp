#include "zoo.h"

Zoo::Zoo()
{
    adresse = "";
}

Zoo::Zoo(string a)
{
    adresse = a;
}

vector<Animal*>::iterator Zoo::chercherAnimal(int mat)
{
    for(vector<Animal*>::iterator it=A.begin(); it!=A.end(); it++){
        if((*it)->getMat() == mat)
            return it;
    }
    return A.end();
}

void Zoo::ajouterAnimal(const Animal &x)
{
    Animal * a = new Animal(x);
    if(chercherAnimal(a->getMat()) != A.end())
        cout << "Animal existe deja" << endl;
    else
        A.push_back(a);
}

void Zoo::ajouterLion(const Lion &x)
{
    Animal * a = new Lion(x);
    if(chercherAnimal(a->getMat()) != A.end())
        cout << "Lion existe deja" << endl;
    else
        A.push_back(a);
}

void Zoo::afficherAnimal()
{
    for(vector<Animal*>::iterator it=A.begin(); it!=A.end(); it++){
        (*it)->afficher(); cout << endl;
    }
}

void Zoo::ajouterDateVaccin(int mat, string date)
{
    vector<Animal*>::iterator it = chercherAnimal(mat);
    if(it != A.end()){
        if((*it)->chercherDate(date) == (*it)->getD().end()) // A questionner: Est-ce que je peux faire getD() function?
            (*it)->ajouterDateVaccin(date);
        else
            cout << "Date existe" << endl;
    }else
        cout << "Animal ne existe pas." << endl;
}

vector<Veterinaire>::iterator Zoo::chercherVeterinaire(int id)
{
    for(vector<Veterinaire>::iterator it=V.begin(); it!=V.end(); it++){
        if(it->getID() == id)
            return it;
    }
    return V.end();
}

void Zoo::ajouterVeterinaire(const Veterinaire &v)
{
    if()
        V.push_back(v);
    else
        cout << "Veterinaire existe deja." << endl;
}
