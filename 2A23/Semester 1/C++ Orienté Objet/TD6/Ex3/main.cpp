#include "epreuve.h"
#include "pratique.h"
#include "quiz.h"
#include "institution.h"

int main()
{
    Institution I;
    Epreuve e1(1, 60);
    Pratique p1(2, 30, 0, 3), p2(4, 60, 1, 4);
    Quiz q1(3, 15, "Math", 5), q2(5, 15, "C++", 5);

    I.ajouter(e1); I.ajouter(p1); I.ajouter(q1); I.ajouter(p2); I.ajouter(q2);
    I.afficher(); cout << endl;
    I.afficherQuiz("Math"); cout << endl;
    I.calculeDuree(); cout << endl;
    I.afficher();
    I.supprimerQuiz("Math"); cout << endl << endl;
    I.afficher();
    I.modifierEx(2); I.calculeDuree(); cout << endl << endl;
    I.afficher();

    return 0;
}
