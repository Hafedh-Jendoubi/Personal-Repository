#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

template <typename U> U myMax(U x, U y)
{
    if(x > y)
        return x;
    else
        return y;
}

template <typename U> void comp_type(U x, U y)
{
    if(x > y)
        cout << x << " > " << y << endl;
    else if(x < y)
        cout << x << " < " << y << endl;
    else
        cout << x << " = " << y << endl;
}

template <typename U> U calculerSomme(U x, U y)
{
    return x + y;
}

template <typename U> float moyenne(vector<U> x)
{
    float moy = 0;
    int i = 0;
    for(vector<int>::iterator it=x.begin(); it!=x.end(); it++){ //Why I can not write " vector<U>::iterator " ?
        moy += (*it);
        i++;
    }
    return moy/i;
}

#endif // FONCTIONS_H_INCLUDED
