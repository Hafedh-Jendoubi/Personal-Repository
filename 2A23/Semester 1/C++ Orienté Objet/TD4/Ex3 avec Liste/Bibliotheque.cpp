#include "Bibliotheque.h"

void Bibilotheque::afficher()
{
    list<Ouvrage>::iterator it;

    for(it=l.begin(); it!=l.end(); it++)
        it->afficher();
}

float Bibilotheque::prixTotal()
{
    list<Ouvrage>::iterator it;
    float sum = 0;

    for(it=l.begin(); it!=l.end(); it++){
        sum += it->totalOuvrage();
    }

    return sum;
}

list<Ouvrage>::iterator Bibilotheque::rechercher(int code)
{
    list<Ouvrage>::iterator it;

    for(it=l.begin(); it!=l.end(); it++){
        if(it->getCode() == code)
            return it;
    }

    return l.end();
}

void Bibilotheque::ajouter(Ouvrage o)
{
    list<Ouvrage>::iterator it;

    it = rechercher(o.getCode());
    if(it == l.end())
        l.push_back(o);
    else
        cout << "Ce ouvrage existe deja" << endl;
}

void Bibilotheque::diminuer(int code, int n)
{
    list<Ouvrage>::iterator it;

    it = rechercher(code);
    if(it!=l.end())
        it->setExp(it->getExp()-n);
    else
        cout << "Ouvrage ayant le code \"" << code << "\" ne existe pas." << endl;
}

void Bibilotheque::augmenter(int code, int n)
{
    list<Ouvrage>::iterator it;

    it = rechercher(code);
    if(it!=l.end())
        it->setExp(it->getExp()+n);
    else
        cout << "Ouvrage ayant le code \"" << code << "\" ne existe pas." << endl;

}
