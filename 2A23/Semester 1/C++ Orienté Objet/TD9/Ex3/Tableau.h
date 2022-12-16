#ifndef TABLEAU_H_INCLUDED
#define TABLEAU_H_INCLUDED
#include <iostream>
using namespace std;

template <class U> class Tableau{
  private:
    U * x;
    int taille;
    int nb;
  public:
    Tableau(){};
    Tableau(int taille);
    ~Tableau();
    Tableau(const Tableau<U> &);
    void afficher();
    Tableau& operator=(const Tableau<U> &);
    Tableau& operator+(const Tableau<U> &);
    Tableau& operator==(const Tableau<U> &);
    Tableau& operator[](const Tableau<U> &);
    void ajouter_fin(U);
    void supprimer(int);
};

template <class U> Tableau<U>::Tableau(int taille)
{
    this->taille = taille;
    x = new U(taille);
    nb = 0;
}

template <class U> Tableau<U>::~Tableau()
{
    delete[] x; //delete[] is used to destroy variables created using new()
}

template <class U> Tableau<U>::Tableau(const Tableau<U> &T)
{
    taille = T.taille;
    nb = T.nb;
    x = new U(taille);
    for(int i=0; i<taille; i++)
        x[i] = T.x[i];
}

template <class U> void Tableau<U>::afficher()
{
    for(int i=0; i<nb; i++)
        cout << x[i] << endl;
    cout << endl;
}

template <class U> void Tableau<U>::ajouter_fin(U a)
{
    x[nb] = a;
    nb++;
}

template <class U> Tableau<U>& Tableau<U>::operator=(const Tableau<U> &T)
{
    if(this != &T){
        taille = T.taille;
        nb = T.nb;
        x = new U(taille);
        for(int i=0; i<nb; i++)
            x[i] = T.x[i];
    }else
        cout << "error!" << endl;

    return *this;
}

template <class U> Tableau<U>& Tableau<U>::operator+(const Tableau<U> &T)
{
    Tableau<U> A(taille+T.taille);

    for(int i=0; i<nb; i++)
        A.x[i] = x[i];
    int i=nb;
    for(int j=0; j<T.nb; j++, i++)
        A.x[i] = T.x[j];
    A.nb = nb + T.nb;

    return A;
}

#endif // TABLEAU_H_INCLUDED
