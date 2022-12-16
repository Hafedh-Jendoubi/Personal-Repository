#include "bibiliotheque.h"

void Bibliotheque::afficher()
{
    std::vector<Ouvrage>::iterator it;
    int i=1;

    for(it=T.begin(); it!=T.end(); it++){
        cout << "Ouvrage n" << i << ":" << endl;
        it->afficher();
        cout << "Prix du stock: " << it->totalOuvrage() << endl << endl;
    }
}

float Bibliotheque::prixTotal()
{
    std::vector<Ouvrage>::iterator it;
    float sum=0;

    for(it=T.begin(); it!=T.end(); it++){
        sum += it->totalOuvrage();
    }

    return sum;
}

vector<Ouvrage>::iterator Bibliotheque::rechercher(int code)
{
    std::vector<Ouvrage>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        if(it->getCode() == code)
            return it;
    }

    return T.end();
}

void Bibliotheque::ajouter(Ouvrage o)
{
    if(rechercher(o.getCode())==T.end())
        T.push_back(o);
    else
        cout << "Ouvrage ayant le code \"" << o.getCode() << "\" existe deja." << endl;
}

void Bibliotheque::diminuerNbExp(int code, int n)
{
    vector<Ouvrage>::iterator it;

    it = rechercher(code);
    if(it!=T.end())
        it->setExp(it->getExp()-n);
    else
        cout << "Ouvrage ayant le code \"" << code << "\" ne existe pas." << endl;

}

void Bibliotheque::augmenterNbExp(int code, int n)
{
    vector<Ouvrage>::iterator it;

    it = rechercher(code);
    if(it!=T.end())
        it->setExp(it->getExp()+n);
    else
        cout << "Ouvrage ayant le code \"" << code << "\" ne existe pas." << endl;
}
