#include "quiz.h"

Quiz::Quiz()
{
    theme = "";
    quest = 0;
}

Quiz::Quiz(int code, int duree, string theme, int quest):Epreuve(code, duree)
{
    this->theme = theme;
    this->quest = quest;
}

void Quiz::afficher()
{
    Epreuve::afficher();
    cout << "Theme: " << theme << endl;
    cout << "Nombre de questions: " << quest << endl;
}
