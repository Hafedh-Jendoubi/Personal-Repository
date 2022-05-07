#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "functions.h"

typedef struct cellule *liste;

void menu(int *ch);
void add_menu(liste *l, int *a);
void delete_menu(liste *l, int *a);
void search_menu(liste *l, int *a);

#endif // MENU_H_INCLUDED
