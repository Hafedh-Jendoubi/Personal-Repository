#include "Notes.h"

Notes::Notes()
{
    test1 = 0;
    test2 = 0;
    DS = 0;
    Examen = 0;
    orale = 0;
    TP = 0;
    avecTP = true;
}

Notes::Notes(float test1, float test2, float DS, float Examen, float orale, float TP)
{
    this->test1 = test1;
    this->test2 = test2;
    this->DS = DS;
    this->Examen = Examen;
    this->orale = orale;
    this->TP = TP;
}

Notes::Notes(float test1, float test2, float DS, float Examen, float orale)
{
    this->test1 = test1;
    this->test2 = test2;
    this->DS = DS;
    this->Examen = Examen;
    this->orale = orale;
    this->avecTP = false;
}

float Notes::calculNCC()
{
    return (test1 + test2 + orale + 2*DS)/5;
}

float Notes::calculMoyenne()
{
    if(avecTP == true)
        return (0.3*calculNCC() + 0.2*TP + 0.5*Examen);
    else
        return (0.4*calculNCC() + 0.6*Examen);
}
