#include "banque.h"

Banque::Banque()
{
    nom = "";
    lieu = "";
}

Banque::Banque(string a, string b)
{
    nom = a;
    lieu = b;
}

vector<Compte*>::iterator Banque::rechercher(int x)
{
    vector<Compte*>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        if((*it)->getRIB() == x)
            return it;
    }

    return T.end();
}

void Banque::ajouter(const Epargne &C)
{
    if(rechercher(C.getRIB()) == T.end()){
        Compte * c = new Epargne(C); //Constructeur par copie!
        T.push_back(c);
    }
}

void Banque::ajouter(const Courant &C)
{
    Compte * c = new Courant(C);
    T.push_back(c);
}

void Banque::afficher()
{
    vector<Compte*>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        (*it)->afficher();
        cout << endl;
    }
}

Banque::Banque(const Banque &B)
{
    Compte * p;
    vector<Compte*>::const_iterator it;
    for(it=B.T.begin(); it!=B.T.end(); it++){
        if(typeid(**it) == typeid(Compte)){
            p = new Compte(**it);
        }else if(typeid(**it) == typeid(Epargne)){
            p = new Epargne(static_cast <const Epargne&>(**it));
        }else{
            p = new Courant(static_cast <const Courant&>(**it));
        }
        T.push_back(p);
    }
}

Banque& Banque::operator=(const Banque &B)
{
    if(this != &B){
        vector<Compte*>::iterator it;
        for(it=T.begin(); it!=T.end(); it++){
            delete(*it);
        }
        Compte * p;
        vector<Compte*>::const_iterator it1;
        for(it1=B.T.begin(); it1!=B.T.end(); it1++){
            if(typeid(**it1) == typeid(Compte)){
                p = new Compte(**it1);
            }else if(typeid(**it1) == typeid(Epargne)){
                p = new Epargne(static_cast <const Epargne&>(**it1));
            }else{
                p = new Courant(static_cast <const Courant&>(**it1));
            }
            T.push_back(p);
        }
    }

    return *this;
}

Banque::~Banque()
{
    vector<Compte*>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        delete(*it);
    }
}
