#ifndef FETE_H_INCLUDED
#define FETE_H_INCLUDED
#include <iostream>
using namespace std;

class Fete{
  public:
    Fete() {cout << "La fete a commence" << endl;}
    ~Fete() {cout << "Ok! Au revoir" << endl;}
    void inviter();
};

#endif // FETE_H_INCLUDED
