#ifndef COMPTE_H_INCLUDED
#define COMPTE_H_INCLUDED

class Compte{
private:
    float solde;
    int numCompte;
public:
    void setSolde(float solde);
    void setNumCompte(int numCompte);
    float getSolde();
};

#endif // COMPTE_H_INCLUDED
