#include "Notes.h"

int main()
{
    Notes n1(10, 12, 15, 11, 17, 9.5), n2(11.5, 13, 18, 10, 12.5);

    if(n1.calculMoyenne() > n2.calculMoyenne())
        cout << "n1 > n2" << endl;
    else
        cout << "n1 < n2  " << endl;

    return 0;
}
