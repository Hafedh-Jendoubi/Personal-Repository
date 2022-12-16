#include "articleSolde.h"

articleSolde::articleSolde()
{
    percentage = 0;
}

articleSolde::articleSolde(string a, double b, double c, float d):Article(a, b, c)
{
    percentage = d;
}

double articleSolde::prixFinal()
{
    return (Article::prixFinal() - (Article::prixFinal()*percentage)/100);
}

void articleSolde::afficher()
{
    Article::afficher();
    cout << "Percentage: " << percentage << "%" << endl;
}
