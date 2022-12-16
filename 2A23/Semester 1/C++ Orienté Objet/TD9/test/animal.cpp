#include "animal.h"

Animal::Animal()
{
    espece = "";
    mat = "";
}

Animal::Animal(string a, string b)
{
    espece = a;
    mat = b;
}

vector<string>::iterator Animal::rechercher(string x)
{
    vector<string>::iterator it;
    for(it=D.begin(); it!=D.end(); it++){
        if((*it) == x)
            return it;
    }

    return D.end();
}

void Animal::ajouterDate(string x)
{
    vector<string>::iterator it = rechercher(x);
    if(it == D.end()){ // Cas unique
        D.push_back(x);
    }else
        cout << "date existe." << endl;
}
