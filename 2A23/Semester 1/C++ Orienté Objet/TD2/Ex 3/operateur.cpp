#include "operateur.h"

void Operateur::init_tab()
{
    for(int i=0; i<50; i++)
        Tab[i].setCIN(-1);
}

void Operateur::ajouter(Abonne a)
{
    int i = 0;

    while(i<50 && Tab[i].getCIN() != -1)
        i++;
    if(i == 50)
        cout << "EROR: Espace insuffisant!" << endl;
    else{
        Tab[i] = a;
    }
}

void Operateur::afficher_list()
{
    for(int i=0; i<50; i++){
        if(Tab[i].getCIN() != -1)
            Tab[i].afficher();
    }
}

void Operateur::modifier_solde(int CIN)
{
    int i = 0;
    float x;

    while(i<50 && Tab[i].getCIN()!= CIN && Tab[i].getCIN() != -1)
        i++;
    if(Tab[i].getCIN() != CIN)
        cout << "CIN Invalid" << endl;
    else{
        cout << "Taper le nouveau solde: "; cin >> x;
        Tab[i].setSolde(x);
        cout << "Mise a jour termine avec succes!" << endl;
    }
}

void Operateur::suppr(int CIN)
{
    int i = 0;

    while(i<50 && Tab[i].getCIN()!=CIN && Tab[i].getCIN() != -1)
        i++;
    if(Tab[i].getCIN() != CIN)
        cout << "CIN Invalid" << endl;
    else{
        Tab[i].setCIN(-1);
        cout << "CIN \" " << CIN << " \" a ete supprimer " << endl;
    }
}
