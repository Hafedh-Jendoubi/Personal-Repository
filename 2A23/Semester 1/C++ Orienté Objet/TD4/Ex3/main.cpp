#include "ouvrage.h"
#include "bibiliotheque.h"

int main()
{
    Bibliotheque B;
    Ouvrage o1(1, "Hafedh", 3, 1.5), o2(2, "Majdi", 5, 0.5);

    B.ajouter(o1);
    B.ajouter(o2);

    B.afficher();
    cout << "Prix total de cette Bibliotheque est: " << B.prixTotal() << endl;

    B.augmenterNbExp(2, 5);
    B.diminuerNbExp(1, 2); cout << endl;
    B.afficher();

    return 0;
}
