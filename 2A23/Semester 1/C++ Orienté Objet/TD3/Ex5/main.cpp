#include "Voyage.h"

int main()
{
    Hebergement H1("Boulevard de la Promenade, 8050 Hammamet, Tunisie", "Yasmine Beach", 5), H2("BP437 / Hammamet 8050 / Tunisie", "la Badira Hammamet", 2);
    Voyage V;

    V.setHebergement(H1);
    V.setEtoiles(1);


    return 0;
}
