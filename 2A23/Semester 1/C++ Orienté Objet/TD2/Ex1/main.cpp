#include <iostream>
#include "Compte.h"
using namespace std;

int main()
{
    Compte c3;
    c3.setSolde(600);
    c3.setNumCompte(1);
    if(c3.getSolde() == 100)
        cout << "----- un d�bit ----" << endl;
        else
        cout << "---- un cr�dit ----" << endl;
    return 0;
}


/**
    1/
        La sortie de ce program est:
            "      ---- un cr�dit ----     "

    2/
        Pour r�soudre cette probl�me il faut de ajouter le terme "private" dans la classe Compte et ajouter les fonctions
    getSolde() and setSolde()
**/
