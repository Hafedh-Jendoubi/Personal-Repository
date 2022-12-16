#include "ouvrage.h"
#include "Bibliotheque.h"

int main()
{
    Bibilotheque B;
    Ouvrage o1(1, "Hafedh", 3, 1.5), o2(2, "Majdi", 5, 0.5);

    B.ajouter(o1);
    B.ajouter(o2);

    B.afficher();
    cout << "Prix total de cette Bibliotheque est: " << B.prixTotal() << endl;

    B.augmenter(2, 5);
    B.diminuer(1, 2); cout << endl;
    B.afficher();

    return 0;
}
