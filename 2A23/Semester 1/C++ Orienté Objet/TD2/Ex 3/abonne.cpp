#include "abonne.h"

int Abonne::getCIN()
{
    return CIN;
}

void Abonne::setCIN(int CIN)
{
    this->CIN = CIN;
}

float Abonne::getSolde()
{
    return solde;
}

void Abonne::setSolde(float solde)
{
    this->solde = solde;
}

void Abonne::saisir()
{
    cout << "Nom: "; cin >> nom;
    cout << "Prenom: "; cin >> prenom;
    cout << "Numero de appelle: "; cin >> num;
    cout << "CIN: "; cin >> CIN;
    cout << "Solde: "; cin >> solde;
}

void Abonne::afficher()
{
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Numero de appelle: " << num << endl;
    cout << "CIN: " << CIN << endl;
    cout << "Solde: " << solde << endl;
}

void Abonne::recharger(float solde)
{
    this->solde = this->solde + solde;
}

bool Abonne::consommer(int sec, float prix)
{
    if(sec > 12){ //If the user has spoken more than 12 seconds which is the default time:
        if((prix/60)*sec > solde)
            return false;
        else{
            this->solde = this->solde - (prix/60)*sec;
            return true;
        }
    }else{ //If the user did not pass the 12 seconds:
        if((prix/60)*12 > solde)
            return false;
        else{
            this->solde = this->solde - (prix/60)*12;
            return true;
        }
    }
}
