#include "video.h"

Video::Video()
{
    editeur = "";
    duree = 0;
}

Video::Video(string a, string b, bool c, string d, float e):Ouvrage(a, b, c)
{
    editeur = d;
    duree = e;
}

void Video::afficher()
{
    Ouvrage::afficher();
    cout << "Editeur: " << editeur << endl;
    cout << "Duree: " << duree << endl;
}
