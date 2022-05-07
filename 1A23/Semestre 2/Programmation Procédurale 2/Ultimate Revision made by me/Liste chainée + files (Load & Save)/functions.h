#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

struct cellule{
    int val;
    struct cellule *next;
};

typedef struct cellule *list;

void menu(int *ch);

void show_list(list l);
list add_element(list l, int x);
list delete_element(list l);
void save_data(list l);
int checkIfFileExists();
list load_data();

#endif // FUNCTIONS_H_INCLUDED