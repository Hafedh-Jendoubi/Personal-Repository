#include "lion.h"

Lion::Lion()
{
    quant = 0;
}

Lion::Lion(string a, string b, float c):Animal(a, b)
{
    quant = c;
}
