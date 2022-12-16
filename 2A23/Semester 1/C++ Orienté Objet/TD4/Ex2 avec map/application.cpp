#include "application.h"

void Application::ajouter(Evenement e)
{
    m[n] = e;
    n++;
}

void Application::afficher(int date)
{
    map<int, Evenement>::iterator it;

    for(it=m.begin(); it!=m.end(); it++){
        if(it->second.getDate() == date){
            it->second.afficher();
            break;
        }
    }
}
