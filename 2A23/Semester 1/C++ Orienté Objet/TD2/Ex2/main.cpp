#include "Compte.h"
#include "Banque.h"

int main()
{
    Compte A1, A2;
    Banque B;

    B.setN(0);

    A1.saisir();
    A1.deposerArgent(100);
    A1.consulterSolde();

    A2.saisir();

    B.ajouter(A1);
    B.ajouter(A2);
    //B.afficherBanque();

    A2.transferer(A1, 250);

    B.afficherBanque();

    A2.consulterSolde();
    return 0;
}
