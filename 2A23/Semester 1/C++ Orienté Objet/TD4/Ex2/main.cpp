#include "evenement.h"
#include "application.h"


int main()
{
    Application a;
    Evenement e1("1994", "Lyon", "culturelle", "Creation de CEP Lyon"), e2("1994", "Paris", "politique", "Mort d'Ayrton Senna"),
              e3("1889", "Paris", "scientifique", "Inauguration tour Eiffel"), e4("1953", "Egypte", "culturelle", " Naissance de John Malkovich"),
              e5("1953", "Canada", "politique", "Naissance de Ségolène Royal 1889");

    a.ajouter(e1);
    a.ajouter(e2);
    a.ajouter(e3);
    a.ajouter(e4);
    a.ajouter(e5);

    a.afficher("1994");

    cout << endl << endl << a.nom_evenement("Creation de CEP Lyon").getNom() << endl; //I used .getNom() just to make sure I found the right Evenement!

    a.regrouper("culturelle");
    a.afficher_evenements();
    a.regrouper("politique");
    a.afficher_evenements();

    return 0;
}
