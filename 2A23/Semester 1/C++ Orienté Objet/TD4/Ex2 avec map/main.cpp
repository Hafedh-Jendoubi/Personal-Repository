#include "evenement.h"
#include "application.h"

int main()
{
    Application a;
    Evenement e1(1994, "Lyon", "culturelle", "Creation de CEP Lyon");

    a.ajouter(e1);
    a.afficher(1994);

    return 0;
}
