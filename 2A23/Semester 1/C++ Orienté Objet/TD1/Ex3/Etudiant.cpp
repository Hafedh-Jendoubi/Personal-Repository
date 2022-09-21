#include "Etudiant.h"

void Etudiant::saisir()
{
    cout << "Nom: "; cin >> nom;
    cout << "Prenom: "; cin >> prenom;
    for(int i=0; i<3; i++){
        cout << "Note " << i+1 << ": ";
        cin >> tab_notes[i];
    }
}

/**
    You can type:
        cout << "Nom: " << nom << endl;
    or you can also type
        ...     ...     << this->nom << endl;
**/

void Etudiant::afficher()
{
    cout << "Nom: " << this->nom << endl;
    cout << "Prenom: " << this->prenom << endl;
    for(int i=0; i<3; i++)
        cout << "Note" << i+1 << ": " << this->tab_notes[i] << endl;
}

float Etudiant::moy()
{
    float moy=0;

    for(int i=0; i<3; i++)
        moy = moy + tab_notes[i];

    return moy/3;
}

bool Etudiant::admis()
{
    return moy()>=10;
}

int Etudiant::exae_quo(Etudiant E)
{
    if(moy()<E.moy())
        return -1;
    else if(moy() == E.moy())
        return 0;
    else
        return 1;
}
