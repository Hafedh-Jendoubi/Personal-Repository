#include "biblio.h"

Biblio::Biblio(const Biblio &B)
{
    Ouvrage * p;
    vector<Ouvrage*>::const_iterator it1;
    for(it1=B.O.begin(); it1!=B.O.end(); it1++){
        if(typeid(**it1) == typeid(Ouvrage))
            p = new Ouvrage(**it1);
        else if(typeid(**it1) == typeid(Livre))
            p = new Livre(static_cast <const Livre&>(**it1));
        else
            p = new Video(static_cast <const Video&>(**it1));
        O.push_back(p);
    }
    A = B.A; //No need for dynamic allocation!
}

Biblio& Biblio::operator=(const Biblio &B)
{
    if(this != &B){
        vector<Ouvrage*>::const_iterator it1;
        for(it1=O.begin(); it1!=O.end(); it1++){
            delete(*it1);
        }
        Ouvrage * p;
        for(it1=B.O.begin(); it1!=B.O.end(); it1++){
            if(typeid(**it1) == typeid(Ouvrage))
                p = new Ouvrage(**it1);
            else if(typeid(**it1) == typeid(Livre))
                p = new Livre(static_cast <const Livre&>(**it1));
            else
                p = new Video(static_cast <const Video&>(**it1));
            O.push_back(p);
        }
        A = B.A;
    }

    return *this;
}

Biblio::~Biblio()
{
    vector<Ouvrage*>::const_iterator it1;
    for(it1=O.begin(); it1!=O.end(); it1++){
        delete(*it1);
    }
    //We do not need to create a destructor for the simple vector 'vector<Abonne>' cause it has no pointers to use 'delete()' on it.
}

vector<Ouvrage*>::iterator Biblio::getOuvrage(string a)
{
    vector<Ouvrage*>::iterator it;

    for(it=O.begin(); it!=O.end(); it++){
        if((*it)->getTitre() == a)
            return it;
    }

    return O.end();
}

void Biblio::ajoutOuvrage(Ouvrage &o1)
{
    if(getOuvrage(o1.getTitre()) == O.end()){ //We have to add const in the function getTitre() in "Ouvrage.h" because we placed a const parametre 'const Ouvrage &'
        o1.setInd(true);
        Ouvrage * o = new Ouvrage(o1);
        O.push_back(o);
    }
}

void Biblio::ajoutOuvrage(Livre &L)
{
    if(getOuvrage(L.getTitre()) == O.end()){
        L.setInd(true);
        Ouvrage * o = new Livre(L);
        O.push_back(o);
    }
}

void Biblio::ajoutOuvrage(Video &V)
{
    if(getOuvrage(V.getTitre()) == O.end()){
        V.setInd(true);
        Ouvrage * o = new Video(V);
        O.push_back(o);
    }
}

void Biblio::supprimerOuvrage(string a)
{
    vector<Ouvrage*>::iterator it = getOuvrage(a);
    if(it != O.end())
        O.erase(it);
}

vector<Abonne>::iterator Biblio::getAbonne(int x)
{
    vector<Abonne>::iterator it;

    for(it=A.begin(); it!=A.end(); it++){
        if(it->getNum() == x)
            return it;
    }

    return A.end();
}

void Biblio::ajoutAbonne(Abonne x)
{
    vector<Abonne>::iterator it = getAbonne(x.getNum());
    if(it == A.end()){
        A.push_back(x);
        cout << "Abonne(e) a ete ajoute(e) avec success." << endl;
    }
}

void Biblio::emprunter(string a, int b)
{
    vector<Ouvrage*>::iterator it = getOuvrage(a);
    vector<Abonne>::iterator it1 = getAbonne(b);
    if(it != O.end() && it1 != A.end()){
        if((*it)->getInd()){
            (*it)->setInd(false);
            it1->setTitre(a);
        }
    }
}

void Biblio::rendre(int x)
{
    vector<Abonne>::iterator it = getAbonne(x);
    if(it != A.end()){
        string ch = it->getTitre();
        it->setTitre("");
        vector<Ouvrage*>::iterator it1 = getOuvrage(ch);
        if(it1 != O.end())
            (*it1)->setInd(true);
        cout << "Ouvrage a ete rendu." << endl;
    }else
        cout << "Abonne(e) ayant le identifiant " << x << " ne existe pas." << endl;
}

void Biblio::info()
{
    cout << "########## Ouvrages: ##########" << endl;
    for(vector<Ouvrage*>::iterator it=O.begin(); it!=O.end(); it++){
        (*it)->afficher();
        cout << endl;
    }
    cout << "########## Abonnes: ##########" << endl;
    for(vector<Abonne>::iterator it1=A.begin(); it1!=A.end(); it1++){
        it1->afficher();
        cout << endl;
    }
    cout << endl;
}

void Biblio::livreAuteur(string a)
{
    vector<Ouvrage*>::iterator it;

    for(it=O.begin(); it!=O.end(); it++){
        if(typeid(**it) == typeid(Livre)){
            Livre * p = (Livre*)(*it);
            if(p->getAuteur() == a)
                p->afficher();
        }
    }
}
