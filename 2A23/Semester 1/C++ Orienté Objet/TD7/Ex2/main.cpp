#include "animal.h"
#include "lion.h"
#include "veterinaire.h"
#include "zoo.h"

int main()
{
    Zoo z;
    Animal a("Herbivor", 100);
    Lion l("Carnivor", 101, 24.5);
    Veterinaire v(1, "Jendoubi", "Hafedh"), v1(2, "Jendoubi", "Majdi");

    z.ajouterAnimal(a); z.ajouterLion(l); z.ajouterVeterinaire(v); z.ajouterVeterinaire(v1);
    z.ajouterDateVaccin(100, "12/12/2022");
    z.afficher();
    z.affecterAnimal(a, v); z.affecterAnimal(l, v); cout << endl << endl;
    z.afficher();

    return 0;
}
