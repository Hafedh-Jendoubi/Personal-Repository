#include "ouvrage.h"
#include "livre.h"
#include "video.h"
#include "abonne.h"
#include "biblio.h"

int main()
{
    Biblio B;
    Livre L("Sky", "22/10", false, "Hafedh");
    Video V("Earth", "06/03", false, "Emna", 120.5);

    B.ajoutOuvrage(L);
    B.ajoutOuvrage(V);
    B.info();
    B.supprimerOuvrage("Sky");
    B.info();

    Abonne a(1, "Jendoubi", 100, "");
    B.ajoutAbonne(a);
    B.emprunter("Earth", 1);
    B.info();
    B.rendre(1);
    B.info();
    B.livreAuteur("Hafedh");

    return 0;
}
