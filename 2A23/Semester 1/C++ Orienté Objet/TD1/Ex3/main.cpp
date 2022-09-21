#include "Etudiant.h"

int main()
{
    Etudiant e1, e2;

    e1.saisir(); e2.saisir();
    cout << endl << endl;
    e1.afficher(); e2.afficher();
    cout << endl << endl;
    cout << "Moyenne 1: " << e1.moy(); cout << endl << "Moyenne 2: " << e2.moy();
    cout << endl << endl;
    cout << e1.admis() << endl; cout << e2.admis();
    cout << endl << endl;
    cout << e1.exae_quo(e2);
    return 0;
}
