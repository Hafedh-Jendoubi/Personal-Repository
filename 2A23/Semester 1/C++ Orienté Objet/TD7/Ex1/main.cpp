#include "produit.h"

int main()
{
    Produit p1(120, "verre V225"), p2(125, "verre V220"), p3;

    p1.ChangerQuantite(12000); p2.ChangerQuantite(50000);
    p1.ChangerPrix(0.125); p2.ChangerPrix(0.100);
    p3 = p1 + p2;
    cout << p1 << endl << p2 << endl;
    cout << p3;
}
