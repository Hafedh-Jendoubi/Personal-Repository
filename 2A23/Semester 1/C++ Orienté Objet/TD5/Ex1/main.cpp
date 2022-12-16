#include "article.h"
#include "articleSolde.h"

int main()
{
    Article a("test", 20, 50);
    articleSolde as("as", 20, 50, 100);

    a.afficher();
    cout << endl << "Le prix Final est: " << a.prixFinal() << endl << endl;
    as.afficher();
    cout << endl << "Le prix Final est: " << as.prixFinal() << endl;
    return 0;
}
