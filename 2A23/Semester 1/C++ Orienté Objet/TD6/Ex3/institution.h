#ifndef INSTITUTION_H_INCLUDED
#define INSTITUTION_H_INCLUDED
#include "epreuve.h"
#include "pratique.h"
#include "quiz.h"
#include <vector>
#include <typeinfo>

class Institution{
  private:
    vector<Epreuve*> Tab;
  public:
    Institution(){};
    Institution(const Institution&);
    Institution& operator=(const Institution&);
    ~Institution();
    void afficher();
    void ajouter(const Epreuve&);
    void ajouter(const Pratique&);
    void ajouter(const Quiz&);
    void afficherQuiz(string);
    void calculeDuree();
    void supprimerQuiz(string);
    void modifierEx(int);
};


#endif // INSTITUTION_H_INCLUDED
