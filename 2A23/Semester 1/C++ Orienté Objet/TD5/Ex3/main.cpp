#include "compte.h"
#include "c_epargne.h"
#include "c_courant.h"

int main()
{
    Compte c;
    C_Epargne ce;
    C_Courant cc;

    c.afficher();
    cout << endl;
    ce.afficher();
    cout << endl;
    cc.afficher();
    cout << endl;
    c.deposer(250);
    c.retirer(100);
    c.afficher();
    cout << endl;
}
