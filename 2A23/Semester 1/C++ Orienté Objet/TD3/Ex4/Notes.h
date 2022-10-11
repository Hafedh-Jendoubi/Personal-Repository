#ifndef NOTES_H_INCLUDED
#define NOTES_H_INCLUDED
#include <iostream>
using namespace std;

class Notes{
  private:
    float test1;
    float test2;
    float DS;
    float Examen;
    float orale;
    float TP;
    bool avecTP;
    float calculNCC();
  public:
    Notes();
    Notes(float, float, float, float, float, float);
    Notes(float, float, float, float, float);
    float calculMoyenne();
};

#endif // NOTES_H_INCLUDED
