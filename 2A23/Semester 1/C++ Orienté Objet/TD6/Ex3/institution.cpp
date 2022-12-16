#include "institution.h"

Institution::Institution(const Institution &I)
{
    vector<Epreuve*>::const_iterator it;
    Epreuve * e;
    for(it=I.Tab.begin(); it!=I.Tab.end(); it++){
        if(typeid(**it) == typeid(Epreuve))
            e = new Epreuve(**it);
        else if(typeid(**it) == typeid(Pratique))
            e = new Pratique(static_cast<const Pratique&>(**it));
        else
            e = new Quiz(static_cast<const Quiz&>(**it));
        Tab.push_back(e);
    }
}

Institution& Institution::operator=(const Institution &I)
{
    vector<Epreuve*>::const_iterator it;
    for(it=Tab.begin(); it!=Tab.end(); it++){
        delete(*it);
    }
    Epreuve * e;
    for(it=I.Tab.begin(); it!=I.Tab.end(); it++){
        if(typeid(**it) == typeid(Epreuve))
            e = new Epreuve(**it);
        else if(typeid(**it) == typeid(Pratique))
            e = new Pratique(static_cast<const Pratique&>(**it));
        else
            e = new Quiz(static_cast<const Quiz&>(**it));
        Tab.push_back(e);
    }
}

Institution::~Institution()
{
    for(vector<Epreuve*>::const_iterator it=Tab.begin(); it!=Tab.end(); it++){
        delete(*it);
    }
}

void Institution::afficher()
{
    for(vector<Epreuve*>::iterator it=Tab.begin(); it!=Tab.end(); it++){
        (*it)->afficher();
        cout << endl;
    }
}

void Institution::ajouter(const Epreuve &e)
{
    Epreuve * ep = new Epreuve(e);
    Tab.push_back(ep);
}

void Institution::ajouter(const Pratique &e)
{
    Epreuve * ep = new Pratique(e);
    Tab.push_back(ep);
}

void Institution::ajouter(const Quiz &e)
{
    Epreuve * ep = new Quiz(e);
    Tab.push_back(ep);
}

void Institution::afficherQuiz(string theme)
{
    cout << "Les Quiz(s) ayant le theme: \"" << theme << "\"" << endl;
    for(vector<Epreuve*>::iterator it=Tab.begin(); it!=Tab.end(); it++){
        if(typeid(**it) == typeid(Quiz)){
            Quiz * q = (Quiz *)(*it);
            if(theme == q->getTheme()){
                q->afficher();
                cout << endl;
            }
        }
    }
}

void Institution::calculeDuree()
{
    cout << "Duree update is done." << endl;
    for(vector<Epreuve*>::iterator it=Tab.begin(); it!=Tab.end(); it++){
        if(typeid(**it) == typeid(Pratique)){
            Pratique * p = (Pratique*) (*it);
            if(p->getInd() == 0) //Test
                p->setDuree(25*p->getEx());
                //AFFICHAGE: cout << "La duree de Epreuve du code '" << p->getCode() << "' est: " << 25*p->getEx() << " (mins)" << endl;
            else if(p->getInd() == 1) // Examen
                p->setDuree(90);
                //AFFICHAGE: cout << "La duree de Epreuve du code '" << p->getCode() << "' est: 90 (mins)" << endl;
        }else if(typeid(**it) == typeid(Quiz)){
            Quiz * q = (Quiz*) (*it);
            q->setDuree(q->getQuest());
            //AFFICHAGE: cout << "La duree de Epreuve du code '" << q->getCode() << "' est: " << q->getQuest() << " (mins)" << endl;
        }
    }
}

void Institution::supprimerQuiz(string theme)
{
    for(vector<Epreuve*>::iterator it=Tab.begin(); it!=Tab.end(); it++){
        if(typeid(**it) == typeid(Quiz)){
            Quiz * q = (Quiz*)(*it);
            if(q->getTheme() == theme)
                Tab.erase(it);
        }
    }
}

void Institution::modifierEx(int x)
{
    for(vector<Epreuve*>::iterator it=Tab.begin(); it!=Tab.end(); it++){
        if((*it)->getCode() == x && typeid(**it) == typeid(Pratique)){
            cout << "Nombre de Exercices: "; int a; cin >> a;
            Pratique * p = (Pratique *) (*it); p->setEx(a);
        }
    }
}
