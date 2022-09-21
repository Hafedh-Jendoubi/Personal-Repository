#include <iostream>

using namespace std;

int main()
{
    string name;

    cout << "Type your name: " << endl;
    getline(cin, name);
    cout << "Your name is, " << name << "."<< endl;

    return 0;
}
