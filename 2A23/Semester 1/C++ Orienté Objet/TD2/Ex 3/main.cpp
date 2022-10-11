#include "abonne.h"
#include "operateur.h"

int main()
{
    Abonne a, a1, a2;
    Operateur O;
    O.init_tab();

    /** Testing Abonnee functions **/

    a.saisir();
    a.recharger(0.05);
    cout << a.consommer(20, 0.18); // I tried everything, it seems working!
    a.afficher();
    cout << endl << endl << " --------------------- "  << endl << endl;

    /** Testing Operateur functions **/

    a1.saisir();
    a2.saisir();
    O.ajouter(a1); O.ajouter(a2);
    O.afficher_list();
    cout << endl;
    O.modifier_solde(a1.getCIN());
    O.afficher_list();
    cout << endl;
    O.suppr(a1.getCIN());
    O.afficher_list();

    return 0;
}
