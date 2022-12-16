#include "note.h"

Note::Note()
{
    id = 0;
    obj = "";
    desc = "";
    date_prise = "";
}

Note::Note(int a, string b, string c, string d)
{
    id = a;
    obj = b;
    desc = c;
    date_prise = d;
}

void Note::afficher()
{
    cout << "ID: " << id << endl;
    cout << "Objet: " << obj << endl;
    cout << "Description: " << desc << endl;
    cout << "Date de prise: " << date_prise << endl;
}
