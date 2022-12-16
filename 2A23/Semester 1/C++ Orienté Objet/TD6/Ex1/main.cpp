#include "compte.h"
#include "epargne.h"
#include "courant.h"
#include "banque.h"

int main()
{
    Banque B;
    Epargne E(100, 2000, 20);
    Courant C(101, 2500, 30);

    B.ajouter(E);
    B.ajouter(C);

    B.afficher();

    /*if(B.rechercher(10) != B.T.end()) //I have changed Banque.h attributs from private to public just to test B.T.end();
        cout << "Compte existe" << endl;
    else
        cout << "Compte inexistant" << endl;*/

    Banque B1(B), B2;
    B2 = B;
    cout << "--------- B1  -------" << endl;
    B1.afficher();
    cout << endl << "--------- B2  -------" << endl;
    B2.afficher();
}
