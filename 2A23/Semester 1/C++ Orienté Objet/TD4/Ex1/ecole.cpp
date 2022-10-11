#include "ecole.h"

vector <Etudiant>::iterator Ecole::rechercher(int x)
{
    vector <Etudiant>::iterator it;
    for(it = T.begin(); it!=T.end(); it++){
        if(it->getNum() == x)
            return it;
    }

    return T.end();
}

void Ecole::ajouter(Etudiant e)
{
    if(rechercher(e.getNum())==T.end()){
        T.push_back(e);
    }
}

void Ecole::afficher()
{
    vector <Etudiant>::iterator it;
    for(it = T.begin(); it!=T.end(); it++){
        it->afficher();
    }
}

void Ecole::supprimer(int x)
{
    if(rechercher(x)!=T.end()){
        T.erase(rechercher(x));
    }
}

void Ecole::rechercher_afficher(string ch)
{
    vector <Etudiant>::iterator it;
    for(it = T.begin(); it!=T.end(); it++){
        if(it->getClass() == ch){
            it->afficher();
        }
    }
}
