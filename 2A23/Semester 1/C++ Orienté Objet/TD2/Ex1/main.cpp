#include <iostream>
#include "Compte.h"
using namespace std;

int main()
{
    Compte c3;
    c3.setSolde(600);
    c3.setNumCompte(1);
    if(c3.getSolde() == 100)
        cout << "----- un débit ----" << endl;
        else
        cout << "---- un crédit ----" << endl;
    return 0;
}


/**
    1/
        La sortie de ce program est:
            "      ---- un crédit ----     "

    2/
        Pour résoudre cette problème il faut de ajouter le terme "private" dans la classe Compte et ajouter les fonctions
    getSolde() and setSolde()
**/
