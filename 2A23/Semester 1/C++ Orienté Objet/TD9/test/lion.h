#ifndef LION_H_INCLUDED
#define LION_H_INCLUDED
#include "animal.h"

class Lion: public Animal{
  private:
    float quant;
  public:
    Lion();
    Lion(string, string, float);
    ~Lion(){};
};

#endif // LION_H_INCLUDED
