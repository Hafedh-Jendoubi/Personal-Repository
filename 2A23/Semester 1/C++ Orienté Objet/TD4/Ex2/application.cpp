#include "application.h"

void Application::afficher(string date)
{
    std::vector<Evenement>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        if(it->getDate() == date)
            cout << it->getDate() << ", " << it->getNom() << ", " << it->getLieu() << ", " << it->getType() << endl;
    }
}

Evenement Application::nom_evenement(string nom)
{
    std::vector<Evenement>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        if(it->getNom() == nom)
            return *it;
    }
}

void Application::regrouper(string type)
{
    vector<Evenement> E;
    vector<Evenement>::iterator it;

    for(it=T.begin(); it!=T.end(); it++){
        if(it->getType() == type){
            E.push_back(*it);
            T.erase(it);
        }
    }
   for(it=E.begin(); it!=E.end(); it++){
        T.push_back(*it);
   }
   cout << "regroupe avec le type " << "\"" << type << " est termine avec succes!" << endl;
}

void Application::afficher_evenements()
{
    std::vector<Evenement>::iterator it;

    cout << endl << "------------------------------------" << endl;
    for(it=T.begin(); it!=T.end(); it++){
        cout << it->getDate() << ", " << it->getNom() << ", " << it->getLieu() << ", " << it->getType() << endl;
    }
    cout << "------------------------------------" << endl;
}
