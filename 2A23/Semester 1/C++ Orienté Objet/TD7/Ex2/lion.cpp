#include "lion.h"

Lion::Lion()
{
    quant = 0;
}

Lion::Lion(string a, int b, float c):Animal(a, b)
{
    quant = c;
}

void Lion::afficher()
{
    Animal::afficher();
    cout << "Quantite de viande consomme: " << quant << " (kg)" << endl;
}
