#include <iostream>
using namespace std;
#include "ecole.h"
#include "etudiant.h"

int main()
{
    Ecole e;
    Etudiant e1("Jendoubi", "Manouba", "2A23", "22/11/2002", 1),
             e2("Gheriani", "Bardo", "2A23", "06/03/2002", 2);

    e.ajouter(e1);
    e.ajouter(e2);

    e.afficher();

    e.supprimer(1);

    e.afficher();

    return 0;
}
