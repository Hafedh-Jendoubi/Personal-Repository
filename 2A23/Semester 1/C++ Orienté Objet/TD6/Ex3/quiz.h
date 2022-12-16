#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED
#include "epreuve.h"
#include <string>

class Quiz: public Epreuve{
  private:
    string theme;
    int quest;
  public:
    Quiz();
    Quiz(int, int, string, int);
    Quiz(Epreuve);
    ~Quiz(){};
    string getTheme(){return theme;};
    int getQuest(){return quest;};
    void afficher();
};

#endif // QUIZ_H_INCLUDED
