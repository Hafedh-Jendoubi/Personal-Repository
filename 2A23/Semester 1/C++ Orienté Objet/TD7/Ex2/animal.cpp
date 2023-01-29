#include "animal.h"

Animal::Animal()
{
    espece = "";
    mat = 0;
}

Animal::Animal(string a, int b)
{
    espece = a;
    mat = b;
}

void Animal::afficher()
{
    cout << "Espece: " << espece << endl;
    cout << "Matricule: " << mat << endl;
    cout << "Date vaccination(s):" << endl;
    for(vector<string>::iterator it=D.begin(); it!=D.end(); it++){
        cout << " [*] " << *it << endl;
    }
}

vector<string>::iterator Animal::chercherDate(string x)
{
    for(vector<string>::iterator it=D.begin(); it!=D.end(); it++){
        if((*it) == x)
            return it;
    }
    return D.end();
}
