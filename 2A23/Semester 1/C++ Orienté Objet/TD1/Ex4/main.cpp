#include "Article.h"
int main()
{
    float tva;
    Article a;

    a.saisir();
    cout << endl << "Donner le taux de TVA pour tous les articles : ";
    cin >> tva;
    cout << "Le taux TVA est : " << tva << "%" << endl;
    a.afficher();
    cout << "Le prix TTC est " << a.prix_ttc(tva) << endl;

    return 0;
}
