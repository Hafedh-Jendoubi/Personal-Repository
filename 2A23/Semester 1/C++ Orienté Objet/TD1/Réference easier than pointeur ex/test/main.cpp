#include <iostream>
using namespace std;

void remplacer(int &a, int &b)
{
    int c;

    c = a;
    a = b;
    b = c;
}

int main()
{
    int a, b;

    a = 1;
    b = 2;
    remplacer(a, b);
    cout << "a = " << a << endl << "b = " << b << endl;

    return 0;
}

/**
    The function remplacer() doesn't have to be like that:

        void remplacer(int *a, int *b)
        {
            int c;

            c = *a;
            *a = *b;
            *b = c;
        }

    In c++ we use something called reference to make things easier which is

        void remplacer(int &a, int &b);
**/
