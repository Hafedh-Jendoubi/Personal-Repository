#include "animal.h"
#include "lion.h"
#include "veterinaire.h"
#include "zoo.h"

int main()
{
    Zoo z;
    Animal a("Herbivor", 100);
    Lion l("Carnivor", 101, 24.5);

    z.ajouterAnimal(a); z.ajouterLion(l);
    z.ajouterDateVaccin(100, "12/12/2022");
    z.afficherAnimal();

    return 0;
}
