#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED
#include "animal.h"

class Lion: public Animal{
  private:
    float quant;
  public:
    Lion();
    Lion(string, int, float);
    ~Lion(){};
    void afficher();
};

#endif // LION_H_INCLUDED
