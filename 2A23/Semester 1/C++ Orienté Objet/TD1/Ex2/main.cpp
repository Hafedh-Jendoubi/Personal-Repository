#include <iostream>

using namespace std;

int main()
{
    string str("Les sanglots longs des violons");
    string st(str, 0, 12);
    cout << "\"" << st << endl; //etape 1

    string str2("de l'automne blessent mon coeur");
    cout << str.replace(str.size()-1, 0, " "+str2) << endl;

    int n=str.find("sanglots");
    cout << n << endl;

    for(int i=0; i<str.size(); i++)
        cout << str.at(i) << " " << str[i] << endl;


    return 0;
}
