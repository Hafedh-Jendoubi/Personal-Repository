#include "Tableau.h"

int main()
{
    Tableau<int> A(5);
    A.ajouter_fin(4);
    A.ajouter_fin(6);
    A.afficher();

    Tableau<int> B(A);
    B.afficher();

    Tableau<int> C;
    C = A;
    C.afficher();

    //Tableau<int> D;

    return 0;
}
