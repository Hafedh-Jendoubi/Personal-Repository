#include "fonctions.h"
#include <iomanip>
int main()
{
    cout << setprecision(3) << myMax(5, 7) << endl;  // To use setprecision() in order to fix how many decimals behind the "," you should include
    comp_type(5.5555, 3.4);                            //  <iomanip> first.
    cout << calculerSomme(3, 5) << endl;

    vector<int> T;
    T.push_back(5); T.push_back(3); T.push_back(2);
    cout << moyenne(T) << endl;

    return 0;
}
