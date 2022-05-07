#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cellule{
    char c;
    struct cellule *suivant;
};

typedef struct cellule *pile;

int bien_paranthesee(char *expr);

#endif // FUNCTIONS_H_INCLUDED
