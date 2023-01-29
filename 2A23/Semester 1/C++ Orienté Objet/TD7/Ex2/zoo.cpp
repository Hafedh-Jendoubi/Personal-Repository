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

void Zoo::afficher()
{
    cout << "~~~~~~~~ Animals: ~~~~~~~~" << endl;
    for(vector<Animal*>::iterator it=A.begin(); it!=A.end(); it++){
        (*it)->afficher(); cout << endl;
    }
    cout << endl << "~~~~~~~~ Doctors: ~~~~~~~~" << endl;
    for(vector<Veterinaire>::iterator it=V.begin();  it!=V.end(); it++){
        it->afficher(); cout << endl;
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
    vector<Veterinaire>::iterator it = chercherVeterinaire(v.getID());
    if(it == V.end())
        V.push_back(v);
    else
        cout << "Veterinaire existe deja." << endl;
}

void Zoo::affecterAnimal(const Animal &a, const Veterinaire &v)
{
    try{
        vector<Animal*>::iterator it = chercherAnimal(a.getMat());
        if(it != A.end()){
            try{
                vector<Veterinaire>::iterator it1 = chercherVeterinaire(v.getID());
                if(it1 != V.end()){
                    it1->affecter(a.getMat());
                }else
                    throw string("Veterinaire ne existe pas.");
            }
            catch(const string &ch){
                cerr << ch << endl;
            }
        }else
            throw string("Animal ne existe pas.");
    }
    catch(const string &ch1){
        cerr << ch1 << endl;
    }
}
