#include "produit.h"

Produit::Produit()
{
    reff = 0;
    lib = "";
}

Produit::Produit(int a, string b)
{
    reff = a;
    lib = b;
}

/*Produit Produit::operator=(const Produit &p)
{
    reff = p.reff;
    lib = p.lib;
    quant = p.quant;
    pu = p.pu;

    return *this;
}*/

Produit Produit::operator+(const Produit &p)
{
    Produit R(reff, lib+p.lib);

    float prix = (pu*quant + p.pu*p.quant)/(quant + p.quant);

    R.ChangerPrix(prix);
    R.ChangerQuantite(quant + p.quant);

    return R;
}

ostream& operator<<(ostream &o, const Produit &p)
{
    return o << p.reff << endl << p.lib << endl << p.quant << endl << p.pu << endl;
}
