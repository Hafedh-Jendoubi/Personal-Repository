#include "zoo.h"

Zoo::Zoo()
{
    adr = "";
}

Zoo::Zoo(string a)
{
    adr = a;
}

Zoo::Zoo(const Zoo &A)
{
    adr = A.adr;
    T2 = A.T2; // ki yebda tableau mehoush dynamic ((maaneha blech eka el *)) donc juste naamlou el affectation '='
    Animal * a; // Zoo A; Zoo B(A); // el objet 'a' hedhi heya eli bch nhotou feha nos5a mel tableau mta3 el 'A' eli heya l'original w el 'B' = copie
    for(vector<Animal*>::const_iterator it=A.T1.begin(); it!=A.T1.end(); it++){
        if(typeid(**it) == typeid(Animal))
            a = new Animal(**it);
        else if(typeid(**it) == typeid(Lion))
            a = new Lion(static_cast <const Lion&>(**it));
        T1.push_back(a);
    }
}

Zoo::~Zoo()
{   //Juste fel desetructeur naamlou destruction mtaa el hajet dynamic kima el tableau T1.
    for(vector<Animal*>::iterator it=T1.begin(); it!=T1.end(); it++)
        delete(*it);
}

Zoo& Zoo::operator=(const Zoo &A)
{
    if(this != &A){ //Hedheya juste bch nodhmnou enou el utilisateur me yektebsh 'A = A' w tnajem tnaheha kima tnaheha kima thotha!
        for(vector<Animal*>::iterator it=T1.begin(); it!=T1.end(); it++)
            delete(*it);
        adr = A.adr;
        T2 = A.T2; // ki yebda tableau mehoush dynamic ((maaneha blech eka el *)) donc juste naamlou el affectation '='
        Animal * a; // Zoo A; Zoo B(A); // el objet 'a' hedhi heya eli bch nhotou feha nos5a mel tableau mta3 el 'A' eli heya l'original w el 'B' = copie
        for(vector<Animal*>::const_iterator it=A.T1.begin(); it!=A.T1.end(); it++){
            if(typeid(**it) == typeid(Animal))
                a = new Animal(**it);
            else if(typeid(**it) == typeid(Lion))
                a = new Lion(static_cast <const Lion&>(**it));
        T1.push_back(a);
        }
    }

    return *this;
}

vector<Animal*>::iterator Zoo::rechercher(string mat)
{
    vector<Animal*>::iterator it;
    for(it=T1.begin(); it!=T1.end(); it++){
        if((*it)->getMat() == mat)
            return it;
    }

    return T1.end();
}

void Zoo::ajouter(const Animal &a)
{
    vector<Animal*>::iterator it = rechercher(a.getMat());
    if(it == T1.end()){ //Cas unique
        Animal * x = new Animal(a); // Me najmoush nzidou animal fi tableau mtaa des pointeurs donc nwaliw naamlu variable jdida de type 'Animal *' bch nhotou feha el copie mta3 les info mta3 el animal a w najmu ndakhluh fel tableau
        T1.push_back(x);
    }else
        cout << "Animal existe." << endl;
}

void Zoo::ajouter(const Lion &l)
{
    vector<Animal*>::iterator it = rechercher(l.getMat());
    if(it == T1.end()){ //Cas unique
        Animal * x = new Animal(l);
        T1.push_back(x);
    }else
        cout << "Animal existe." << endl;
}

void Zoo::ajouterDate(string mat, string date)
{
    vector<Animal*>::iterator it = rechercher(mat);
    if(it != T1.end()){ //Cas animal n'existe pas
        cout << "animal ne existe pas" << endl;
    }else{
        (*it)->ajouterDate(date);
    }
}

vector<Medecin>::iterator Zoo::rechercher(int id)
{
    vector<Medecin>::iterator it;
    for(it=T2.begin(); it!=T2.end(); it++){
        if(it->getID() == id)
            return it;
    }

    return T2.end();
}

void Zoo::ajouter(const Medecin &m)
{
    vector<Medecin>::iterator it = rechercher(m.getID());
    if(it == T2.end()){ //Cas unique
        T2.push_back(m);
    }else
        cout << "Medecin existe." << endl;
}
